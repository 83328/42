#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>

typedef struct s_client
{
    int id;
    char *buffer;
} t_client;

t_client clients[1024];
fd_set active_fds, read_fds, write_fds;
int max_fd = 0, next_id = 0;
char send_buffer[4096], recv_buffer[4096];

void fatal_error()
{
    write(2, "Fatal error\n", strlen("Fatal error\n"));
    exit(1);
}

void send_to_all(int sender_fd, const char *message)
{
    for (int i = 0; i <= max_fd; i++) {
        if (FD_ISSET(i, &write_fds) && i != sender_fd)
        {
            if (send(i, message, strlen(message), 0) < 0)
            {
                fatal_error();
            }
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        write(2, "Wrong number of arguments\n", strlen("Wrong number of arguments\n"));
        return 1;
    }

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) fatal_error();

    struct sockaddr_in server_addr =
    {
        .sin_family = AF_INET,
        .sin_addr.s_addr = htonl(INADDR_LOOPBACK), // 127.0.0.1
        .sin_port = htons(atoi(argv[1]))
    };

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0 || listen(server_fd, 128) < 0)
    {
        fatal_error();
    }

    FD_ZERO(&active_fds);
    FD_SET(server_fd, &active_fds);
    max_fd = server_fd;

    while (1)
    {
        read_fds = write_fds = active_fds;
        if (select(max_fd + 1, &read_fds, &write_fds, NULL, NULL) < 0) continue;

        for (int fd = 0; fd <= max_fd; fd++)
        {
            if (FD_ISSET(fd, &read_fds))
            {
                if (fd == server_fd)
                {
                    int client_fd = accept(server_fd, NULL, NULL);
                    if (client_fd < 0) continue;

                    max_fd = client_fd > max_fd ? client_fd : max_fd;
                    clients[client_fd].id = next_id++;
                    clients[client_fd].buffer = NULL;
                    FD_SET(client_fd, &active_fds);

                    sprintf(send_buffer, "server: client %d just arrived\n", clients[client_fd].id);
                    send_to_all(client_fd, send_buffer);
                } 
                else
                {
                    int ret = recv(fd, recv_buffer, sizeof(recv_buffer) - 1, 0);
                    if (ret <= 0)
                    {
                        sprintf(send_buffer, "server: client %d just left\n", clients[fd].id);
                        send_to_all(fd, send_buffer);

                        free(clients[fd].buffer);
                        clients[fd].buffer = NULL;
                        FD_CLR(fd, &active_fds);
                        close(fd);
                    }
                    else
                    {
                        recv_buffer[ret] = '\0';
                        clients[fd].buffer = str_join(clients[fd].buffer, recv_buffer);

                        char *msg;
                        while (extract_message(&clients[fd].buffer, &msg))
                        {
                            sprintf(send_buffer, "client %d: %s\n", clients[fd].id, msg);
                            send_to_all(fd, send_buffer);
                            free(msg);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
