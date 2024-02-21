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

int main(int argc, char *argv[], char *envp[])
{
	t_struct	*stru;
	int			i;
	int			j;
	int			k;
	int			len;
	pid_t		pid;

	(void)argc;
	(void)argv;
	stru = ft_calloc(1,sizeof(t_struct));
	stru->ufd_i = 0;
	envp_handling(envp, stru);
	signal_handling();
	while (1) 
	{
		stru->input = readline("minishell >> ");
		if (!stru->input)
		{
			printf("exit\n");
			break;
		}
		if (ft_strcmp(stru->input, "") == 0)
			continue; //should be called skip, because it skips the rest of this loop iteration
		add_history(stru->input);
		stru->input_by_pipes = pipe_split(stru->input);
		i = 0;
		j = 0;
		len = 0;
		while (stru->input_by_pipes[len])
			len++;
		stru->reassembled_commands = ft_calloc((len + 1 + 1),sizeof(char *));
		stru->reassembled_commands[j] = ft_strdup("junk_program_name");
		j++;
		stru->filefds = ft_calloc((2 * len) + 1,sizeof(int )); //pointer because it will be an array with one potential infile and one potential outile
		while (stru->input_by_pipes[i])			//needs to be parsed for redirection operators
		{
			stru->split_by_space = space_split(stru->input_by_pipes[i]); //needs to reduce to one space, needs to leave quoted spaces intact
			open_files(stru,i);		//opens files and saves fds in struct
			rem_redir(stru->split_by_space); //removes redirection operators and files from split_by_space
			k = 0;
			while (stru->split_by_space[k])
				k++;
			stru->reassembled_commands[j] = line_expansion(concat_strings(stru->split_by_space,k));
			i++;
			j++;
		}
		terminate_filefds(stru, i);
		printIntArray2D(stru->filefds);
		printIntArray(stru->unused_fds);
		stru->reassembled_commands[j] = NULL;
		printStringArray(stru->reassembled_commands);
		pid = fork();
		if (pid)
			waitpid(pid, NULL, 0);
		else
		pipex_plus(len, stru->reassembled_commands, envp, stru);

	}
	return 0;
}