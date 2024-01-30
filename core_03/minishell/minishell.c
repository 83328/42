#include "minishell.h"

int global_sig = 0;

int get_length(char **split_input)
{
    int length = 0;
    while (split_input[length] != NULL)
    {
        length++;
    }
    return length;
}

void execute_command(char **split_input)
{
    global_sig = 1;
    extern char **environ;
    pid_t pid = fork();
    int length = get_length(split_input);

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    { // Child process
       // if (split_input[0] != NULL)
      //  {
            if (strcmp(split_input[0], "echo") == 0)
            {
                echo_command_with_split_input(split_input, length);
            }
            else if (strcmp(split_input[0], "pwd") == 0)
            {
                char *currentDir = pwd();
                if (currentDir)
                {
                    printf("%s\n", currentDir);
                    free(currentDir);
                }
                else
                {
                    perror("pwd");
                }
            }
     //   }
        else if (strcmp(split_input[0], "cd") == 0)
        {
            if (split_input[1] == NULL)
            {
                fprintf(stderr, "Usage: cd <directory>\n");
            }
            else
            {
                char *cd_args[] = {"cd", split_input[1], NULL};
                cd_command(2, cd_args);
            }
        }
        else if (strcmp(split_input[0], "env") == 0)
        {
            env_command(environ);
        }
        else if (strcmp(split_input[0], "unset") == 0)
        {
            unset_command(split_input[1]);
        }
        else if (strcmp(split_input[0], "export") == 0)
        {
            if (split_input[1] != NULL)
            {
                export_command(split_input[1]);
            }
            else
            {
                env_command();
            }
        }
        else if(strcmp(split_input[0], "exit") == 0)
        {
            exit(EXIT_SUCCESS);
        }
        else
        {
            // If the command is not a built-in command, execute it with execvp
            if (execvp(split_input[0], split_input) == -1)
            {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        }
        // Exit the child process
        exit(EXIT_SUCCESS);
    }
    else
    { // Parent process
        int status;
        //printf("Waiting for input...\n");
        waitpid(pid, &status, 0);
        // Handle status if needed
    }
}

int main()
{
	char    *input;
	char    **split_input;
	char    *expanded_input;

	input = NULL;

	signal(SIGINT, sigint_handler); //ctrl-c
	signal(SIGQUIT, SIG_IGN); //ctrl-backslash
	signal(SIGTSTP, SIG_IGN); //ctrl-z
	while (1)
	{
		//signal(SIGINT, sigint_handler);
		input = readline("minishell $ ");
		// if (input != NULL)
		//     printf("%s\n",input);
		if (!input)
		{
			printf("exit\n");
			break;
		}
		expanded_input = dollars_expansion(input);

        //printf("\n expanded input: %s",expanded_input);
		split_input = ft_split(expanded_input, ' '); // more sophisticated
		// // If the user entered a command, add it to the history
		// if (input[0])
		// {
		// 	add_history(input);
		// }
		// // Check for exit command
    if (split_input != NULL && split_input[0] != NULL && ft_strcmp(split_input[0], "exit") == 0)
    {
        free(input);
        break;
    }
		// Execute the command
        printf("input: %s\n", input);
		execute_command(split_input);
		global_sig = 0;
		//free(input);
	}
	return 0;
}
