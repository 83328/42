/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:45:13 by alimpens          #+#    #+#             */
/*   Updated: 2023/12/05 11:30:23 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void parse_input(char *input, char **tokens) {
    // Implement your tokenization logic here
}

void execute_command(char **args, int input_fd, int output_fd) {
    // Implement command execution logic here
    // Use input_fd and output_fd for input and output redirection
}

int handle_builtin(char **args) {
    // Implement built-in command handling here
    // Return 1 if the command is a built-in, 0 otherwise
}

void handle_signal(int signo) {
    // Implement signal handling logic here
}

int main() {
    signal(SIGINT, handle_signal);
    signal(SIGQUIT, SIG_IGN);

    char input[MAX_INPUT_SIZE];
    char *tokens[MAX_TOKENS];

    while (1) {
        printf("minishell> ");
        fgets(input, sizeof(input), stdin);

        input[strcspn(input, "\n")] = '\0';

        parse_input(input, tokens);

        if (handle_builtin(tokens)) {
            continue;
        }

        // Initialize pipes
        int pipe_fds[2];
        int input_fd = STDIN_FILENO;

        for (int i = 0; tokens[i] != NULL; i++) {
            // Check for pipe symbol
            if (strcmp(tokens[i], "|") == 0) {
                // Create pipe
                if (pipe(pipe_fds) == -1) {
                    perror("pipe");
                    exit(EXIT_FAILURE);
                }

                // Execute command with input from the previous command
                execute_command(tokens, input_fd, pipe_fds[1]);

                // Close write end of the pipe
                close(pipe_fds[1]);

                // Set the input for the next command
                input_fd = pipe_fds[0];
            }
        }

        // Execute the last command with the final output
        execute_command(tokens, input_fd, STDOUT_FILENO);

        // TODO: Implement history handling
        // TODO: Implement $? handling
    }

    return 0;
}
