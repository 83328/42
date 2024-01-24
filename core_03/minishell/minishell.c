#include "minishell.h"

int global_sig = 0;

void execute_command(char **split_input)
{
    global_sig = 1;
    extern char **environ;
    pid_t pid = fork();

    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    { // Child process
        if (strcmp(split_input[0], "echo") == 0)
        {
            int i = 1;
            int ac = 0;
            char *av[MAX_ARGS]; // Assuming MAX_ARGS is defined appropriately

            // Copy the arguments into av array, including the command itself
            av[ac] = strdup(split_input[0]); // Copy the command
            if (av[ac] == NULL)
            {
                perror("strdup");
                exit(EXIT_FAILURE);
            }
            ac++;

            while (split_input[i] != NULL)
            {
                // Process quotes before strdup
                // Skip empty tokens after processing quotes
                if (split_input[i][0] != '\0')
                {
                    av[ac] = strdup(split_input[i]);
                    if (av[ac] == NULL)
                    {
                        perror("strdup");
                        // Free allocated memory before exiting
                        while (ac > 0)
                        {
                            free(av[--ac]);
                        }
                        exit(EXIT_FAILURE);
                    }
                    ac++;
                }
                i++;
            }
            // Call the echo_command function
            echo_command(ac, av);

            // Free memory for each string in av
            int j = 0;
            while (j < ac)
            {
                free(av[j]);
                j++;
            }
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
        
        // Insert other commands here

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

        printf("\n expanded input: %s",expanded_input);
		split_input = ft_split(expanded_input, ' '); // more sophisticated
		// // If the user entered a command, add it to the history
		// if (input[0])
		// {
		// 	add_history(input);
		// }
		// // Check for exit command
	if (ft_strcmp(split_input[0], "exit") == 0)
	{
	free(input);
	break;
	}
		// Execute the command
		execute_command(split_input);
		global_sig = 0;
		//free(input);
	}
	return 0;
}
