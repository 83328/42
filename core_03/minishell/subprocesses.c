#include "minishell.h"

void    printpidArray(pid_t *pidArray,int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		printf("\npidArr[%d] %i", i ,pidArray[i]);
		i++;
	}
	printf("\n");
}

pid_t	subprocess(int pos, char **reassembled_commands, char **env, t_struct *stru, int len);
void    dup_io(int **pipefds, int (*filefds)[2], char **reassembled_commands, int pos);
void    dup_input(int **pipefds, int (*filefds)[2], int pos);
void    dup_output(int **pipefds, int (*filefds)[2], char **reassembled_commands, int pos);
int		**create_pipes(int len);
void	close_fds(int **pipefds, int (*filefds)[2], int unused_fds[8192], int len);
//void	close_fds_child(int **pipefds, int (*filefds)[2], int unused_fds[8192], int pos, int len);


void	subprocesses(int len, char **reassembled_commands, char **envp, t_struct *stru)
{
	int     i;

	i = 0;

	stru->pipefds = create_pipes(len - 1);
	while (i < len)
	{
		stru->pids[i] = subprocess(i, reassembled_commands, envp, stru, len);
		i++;
	}
	stru->pids[i] = -1;
	i = 0;
	//printpidArray(stru->pids,len);
	close_fds(stru->pipefds, stru->filefds, stru->unused_fds, len);
	while (stru->pids[i] != -1)
	{
		waitpid(stru->pids[i], &stru->exit_status, 0);
		//dprintf(2,"ex: %d",stru->exit_status);
		i++;
	}
	// free stuff maybe
}

pid_t   subprocess(int pos, char **reassembled_commands, char **env, t_struct *stru, int len)
{
	pid_t   pid;

	pid = fork();
	if (pid == 0)
	{
		dup_io(stru->pipefds, stru->filefds, reassembled_commands, pos);
		close_fds(stru->pipefds, stru->filefds, stru->unused_fds, len);
		//free stuff maybe
		mod_execve(reassembled_commands[pos], env, stru);
		perror_exit("child process failed");
	}
	return(pid);
}

void    dup_io(int **pipefds, int (*filefds)[2], char **reassembled_commands, int pos)
{
	dup_input(pipefds, filefds, pos);
	dup_output(pipefds, filefds, reassembled_commands, pos);
}

void	dup_input(int **pipefds, int (*filefds)[2], int pos)
{
	if(pos == 0)
	{
		if (filefds[0][0] != 0)
			dup2(filefds[0][0],STDIN);
	}
	else
	{
		if (filefds[pos][0] != 0)
			dup2(filefds[pos][0], STDIN);
		else
			dup2(pipefds[pos-1][0],STDIN);
	}
}

void	dup_output(int **pipefds, int (*filefds)[2], char **reassembled_commands, int pos)
{
	if (reassembled_commands[pos+1] == 0)
	{
		if (filefds[pos][1])
			dup2(filefds[pos][1],STDOUT);
	}
	else
	{
		if(filefds[pos][1])
			dup2(filefds[pos][1],STDOUT);
		else
			dup2(pipefds[pos][1], STDOUT);
	}
}

int	**create_pipes(int len)
{
	int i;
	int **pipefds;

	pipefds = ft_calloc(sizeof(int*), len + 1);
	i = 0;
	while (i < len)
	{
		pipefds[i] = malloc(sizeof(int) * 2);
		pipe(pipefds[i]);
		i++;
	}
	return(pipefds);
}

void	close_fds(int **pipefds, int (*filefds)[2], int unused_fds[8192], int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (filefds[i][0] != 0)
			close(filefds[i][0]);
		if (filefds[i][1] != 0)
			close(filefds[i][1]);
		i++;
	}
	i = 0;
	while (i < len -1)
	{
		close(pipefds[i][0]);
		close(pipefds[i][1]);
		i++;
	}
	i = 0;
	while (i < 8192)
	{
		if (unused_fds[i] != 0)
			close(unused_fds[i]);
		i++;
	}
}

// void	close_fds_child(int **pipefds, int (*filefds)[2], int unused_fds[8192], int len, int pos)
// {
// 	int i;

// 	while (i < len)
// 	{
// 		close(pipefds[i][0]);
// 		close(pipefds[i][1]);
// 		close(filefds[i][0]);
// 		close(filefds[i][1]);
// 		i++;
// 	}


// 	i = 0;
// 	while (i < 8192)
// 	{
// 		if (unused_fds[i] != 0)
// 			close(unused_fds[i]);
// 		i++;
// 	}
// }