/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subprocesses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:21 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/26 16:40:42 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	printpidarray(pid_t *pidarray, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("\npidArr[%d] %i", i, pidarray[i]);
		i++;
	}
	printf("\n");
}

pid_t	subprocess(int pos, char **reassembled_commands, char **env, t_struct *stru, int len);
void	dup_io(int **pipefds, int (*filefds)[2], char **reassembled_commands, int pos);
void	dup_input(int **pipefds, int (*filefds)[2], int pos);
void	dup_output(int **pipefds, int (*filefds)[2], char **reassembled_commands, int pos);
int		**create_pipes(int len);
void	close_fds(int **pipefds, int (*filefds)[2], int unused_fds[8192], int len);
//void	close_fds_child(int **pipefds, int (*filefds)[2], int unused_fds[8192], int pos, int len);

void	subprocesses(int len, char **reassembled_commands, char **envp, t_struct *stru)
{
	int	i;

	global_sig = 1;
	i = 0;
	stru->pipefds = create_pipes(len - 1);
	//signal(SIGQUIT, sigquit_handler_command);
	signal(SIGINT, sigint_handler_command);
	while (i < len)
	{
		stru->pids[i] = subprocess(i, reassembled_commands, envp, stru, len);
		i++;
	}
	stru->pids[i] = -1;
	i = 0;
	//printpidarray(stru->pids,len);
	close_fds(stru->pipefds, stru->filefds, stru->unused_fds, len);
	stru->exit_statuses = calloc(len +1, sizeof(int));
	while (stru->pids[i] != -1)
	{
		signal(SIGINT, SIG_IGN);
		waitpid(stru->pids[i], &stru->exit_statuses[i], WUNTRACED);
		// if (WIFEXITED(stru->exit_statuses[i]))
		// 	stru->exit_statuses[i] = WEXITSTATUS(stru->exit_statuses[i]);
		// else 
		if (WIFSIGNALED(stru->exit_statuses[i]))
		{
			stru->exit_statuses[i] = WTERMSIG(stru->exit_statuses[i]) + 128;
			stru->flag = stru->exit_statuses[i];
		}
		i++;
	}
	if (stru->flag == 130)
		ft_putendl_fd("", 2);
	stru->exit_statuses[i] = 0;
	stru->exit_status = stru->exit_statuses[i-1];
	signal(SIGINT, sigint_handler_default);
	signal(SIGQUIT,SIG_IGN);
}

pid_t	subprocess(int pos, char **reassembled_commands, char **env, t_struct *stru, int len)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup_io(stru->pipefds, stru->filefds, reassembled_commands, pos);
		close_fds(stru->pipefds, stru->filefds, stru->unused_fds, len);
		//free stuff maybe
		mod_execve(reassembled_commands[pos], env, stru);
		perror_exit("child process failed");
	}
	return (pid);
}

void	dup_io(int **pipefds, int (*filefds)[2], char **reassembled_commands, int pos)
{
	dup_input(pipefds, filefds, pos);
	dup_output(pipefds, filefds, reassembled_commands, pos);
}

void	dup_input(int **pipefds, int (*filefds)[2], int pos)
{
	if (pos == 0)
	{
		if (filefds[0][0] != 0)
			dup2(filefds[0][0], STDIN);
	}
	else
	{
		if (filefds[pos][0] != 0)
			dup2(filefds[pos][0], STDIN);
		else
			dup2(pipefds[pos -1][0], STDIN);
	}
}

void	dup_output(int **pipefds, int (*filefds)[2], char **reassembled_commands, int pos)
{
	if (reassembled_commands[pos +1] == 0)
	{
		if (filefds[pos][1])
			dup2(filefds[pos][1], STDOUT);
	}
	else
	{
		if (filefds[pos][1])
			dup2(filefds[pos][1], STDOUT);
		else
			dup2(pipefds[pos][1], STDOUT);
	}
}

int	**create_pipes(int len)
{
	int	i;
	int	**pipefds;

	pipefds = ft_calloc(sizeof(int *), len + 1);
	i = 0;
	while (i < len)
	{
		pipefds[i] = malloc(sizeof(int) * 2);
		pipe(pipefds[i]);
		i++;
	}
	return (pipefds);
}

void	close_fds(int **pipefds, int (*filefds)[2], int unused_fds[8192], int len)
{
	int	i;

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
	while (unused_fds[i] != -1)
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