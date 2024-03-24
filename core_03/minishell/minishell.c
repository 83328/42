#include "minishell.h"

int global_sig = 0;

void printIntArray2D(int (*arr)[2]) 
{
    while (arr[0][0] != -1 && arr[0][1] != -1) 
	{
        printf("\n[%d, %d]\n", arr[0][0], arr[0][1]);
        arr++;
    }
}

void unsetEnvVar(char **envp, const char *varname)
{
    int i, j;
    int env_count = 0;

    // Count the number of environment variables
    while (envp[env_count] != NULL) {
        env_count++;
    }

    // Find the environment variable to unset
    for (i = 0; i < env_count; i++) {
        if (strncmp(envp[i], varname, strlen(varname)) == 0 && envp[i][strlen(varname)] == '=') {
            // Free memory for the variable
            free(envp[i]);
            // Shift subsequent elements to fill the gap
            for (j = i; j < env_count - 1; j++) {
                envp[j] = envp[j + 1];
            }
            envp[j] = NULL; // Set the last element to NULL
            break;
        }
    }
}

void	quote_errors(char *input)
{
	int i;

	i = 0;
	while(input[i] != 0 && input[i] != 39 && input[i] != 34) //not null, single quote, double quote
		i++;
	if (input[i] == 39 || input[i] == 34 )
	{
		if(input[i] == 39)
		{
			i++;
			while(input[i] != 39)
			{
				if (input[i] == 0)
					error_exit("unclosed single quote, invalid input\n");
				i++;
			}
		}
		if(input[i] == 34)
		{
			i++;
			while(input[i] != 34)
			{
				if (input[i] == 0)
					error_exit("unclosed double quote, invalid input\n");
				i++;
			}
		}
	}
}

int main(int argc, char *argv[], char *envp[])
{
	t_struct	*stru;
	int			i;
	int			j;
	int			k;
	int			len;

	(void)argc;
	(void)argv;
	stru = ft_calloc(1,sizeof(t_struct));
	stru->ufd_i = 0;
	copy_env(envp, stru);
	signal_handling();
	//set("?", ft_itoa(0), stru);
	while (1)
	{
		stru->input = readline("minishell ## ");
		if (!stru->input)
		{
			printf("exit\n");
			break;
		}
		if (strcmp(stru->input, "") == 0)
			continue ;
		if (strcmp(stru->input, "exit") == 0)
		{
			printf("exit\n");
			break;
		}
		quote_errors(stru->input);
		add_history(stru->input);
		stru->input_by_pipes = pipe_split(stru->input);
		i = 0;
		j = 0;
		len = 0;
		while (stru->input_by_pipes[len])
			len++;
		stru->reassembled_commands = ft_calloc((len + 1 + 1),sizeof(char *));
		stru->filefds = ft_calloc((2 * len) + 1, sizeof(int )); //pointer because it will be an array with one potential infile and one potential outile
		stru->pids = ft_calloc( len + 1, sizeof(pid_t));
		while (stru->input_by_pipes[i])			//needs to be parsed for redirection operators
		{
			stru->split_by_space = space_split(stru->input_by_pipes[i]); //needs to reduce to one space, needs to leave quoted spaces intact
			open_files(stru,i);		//opens files and saves fds in struct
			rem_redir(stru->split_by_space); //removes redirection operators and files from split_by_space
			k = 0;
			while (stru->split_by_space[k])
				k++;
			stru->reassembled_commands[j] = line_expansion(concat_strings(stru->split_by_space,k),stru);
			if (stru->reassembled_commands[j] == NULL) {
				// printf("error: unclosed double quotes4\n");
				break;
			}
			i++;
			j++;
		}
		terminate_filefds(stru, i);
		if (stru->reassembled_commands[j] == NULL){

			// printf("probable segfault start1\n");
			if (stru->reassembled_commands[0] == NULL){

				// printf("probable segfault start2\n");
				continue; //should be called skip, because it skips the rest of this loop iteration
			}
			// continue; //should be called skip, because it skips the rest of this loop iteration
		}
		stru->reassembled_commands[j] = NULL;
		// printf("\n\n\nprobable segfault start1\n\n\n");
		if (!strcmp(stru->reassembled_commands[0], "")){

			// printf("probable segfault start1\n");
			continue; //should be called skip, because it skips the rest of this loop iteration
		}
		else if(strncmp(stru->reassembled_commands[0], "cd", 2) == 0 && i ==1)
		{
			// printf("probable segfault start\n");
			cd_command(stru, stru->split_by_space);
		}
		// else if (strncmp(stru->reassembled_commands[0], "echo", 4) == 0)
		// {
		// 		printf("reassembled_command -->%s<--\n", stru->reassembled_commands[0]);
		// // 		printf("echo --> %s\n", stru->reassembled_commands[1]);
		//  		echo_command(stru->reassembled_commands[0]);
		// }

		else if (strncmp(stru->reassembled_commands[0], "export", 6) == 0)
		{
			// printf("probable segfault start3\n");
			export_command(stru->split_by_space[0], stru->split_by_space[1], stru);
		}
/* 		else if (strncmp(stru->reassembled_commands[0], "unset", 5) == 0)
		{
			unset_command(stru->split_by_space, stru);
		} */
		else
		{
			global_sig = 1;
			subprocesses(len, stru->reassembled_commands, envp, stru);
		}
		// printf("segfault start3\n");
		global_sig = 0;
		unset(stru->env_copy,"?"); //unsets previous exit status, should be done every run
		set("?", ft_itoa(stru->exit_status), stru); // adds exit status to env, should be done every run
		//printStringArray(stru->env_copy); // OFT only for testing
		wait(NULL);
		free(stru->input);
	}
	return 0;
}
