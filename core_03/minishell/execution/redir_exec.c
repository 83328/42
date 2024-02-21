#include "../minishell.h"

void	redir_exec(char *command, char **env, int i, t_struct *stru)
{
	pid_t	pid;
	int		pipefd[2];

	pipe(pipefd);
	pid = fork();
	if(pid)
	{
		close(pipefd[1]);
		if (stru->filefds[i][0])
			dup2(stru->filefds[i][0],STDIN);
		else
			dup2(pipefd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		if (stru->filefds[i-1][1])
			dup2(stru->filefds[i-1][1],STDOUT);
		else
			dup2(pipefd[1], STDOUT);
		close(pipefd[1]);
		// if (i == 1)
		// 	exit(1);
		// else
		mod_execve(command, env);
	}
}