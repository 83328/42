#include "minishell.h"

int global_sig = 0;

void execute_command(char **split_input) 
{
	global_sig = 1;
	pid_t pid = fork();
	//char *path = getenv("PATH");

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0) // Child process
	{
		//execlp("/bin/sh", "sh", "-c", command, NULL);
		//mod_execvp(split_input[0], split_input, path);
		if (strcmp(split_input[0], "echo") == 0)
		{
			int i = 1;
			int ac = 0;
			char *av[MAX_ARGS]; // Assuming MAX_ARGS is defined appropriately

			// Copy the arguments into av array, including the command itself
			av[ac] = strdup(split_input[0]); // Copy the command
			ac++;

			while (split_input[i] != NULL)
			{
				// Process quotes before strdup
				process_quotes(split_input[i]);
				
				// Skip empty tokens after processing quotes
				if (split_input[i][0] != '\0')
				{
					av[ac] = strdup(split_input[i]);
					ac++;
				}

				i++;
			}

			// Call the echo_command function
			echo_command(ac, av);
		}

		else if (strcmp(split_input[0], "pwd") == 0)
		{
//			printf("pwd command goes here\n");
			char *currentDir = pwd();
			if(currentDir)
			{
				printf("%s\n", currentDir);
				free(currentDir);
 			 }
			else
				perror("pwd");
		}
		else if (strcmp(split_input[0], "cd") == 0)
		{
			printf("cd command goes here\n");
		}
		//Insert other commands here

	}
	else // Parent process
	{
		int status;
		waitpid(pid, &status, 0);
		// Handle status if needed
	}
}

void sigint_handler(int sig)
{
	if (sig == SIGINT && global_sig == 0)
	{
		// rl_on_new_line();
		// rl_replace_line("", 0);  // Clear the current input line
		// //printf("minishell $ ");
		//rl_redisplay();
		printf("\n");
		printf("minishell $ ");
		//printf("test2");
	}
	else if (sig == SIGINT && global_sig == 1)
	{
		//rl_on_new_line();// Move to a new line
		//rl_redisplay();
		printf("\n");
	}
	//printf("minishell $ ");  // Redisplay the prompt
	//input = readline("minishell >> ");
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