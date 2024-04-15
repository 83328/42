/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subprocesses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <dgacic@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 16:40:22 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/12 16:40:25 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	subprocess(int pos, 
			char **reassembled_commands, t_struct *stru, int len);
int		**create_pipes(int len);
void	close_fds(int **pipefds, 
			int (*filefds)[2], int unused_fds[8192], int len);

int	wait_loop(t_struct *stru, int i)
{
	waitpid(stru->pids[i], &stru->exit_statuses[i], WUNTRACED);
	signal(SIGINT, SIG_IGN);
	if (WIFSIGNALED(stru->exit_statuses[i]))
	{
		stru->exit_statuses[i] = WTERMSIG(stru->exit_statuses[i]) + 128;
		stru->flag = stru->exit_statuses[i];
	}
	else if (WIFEXITED(stru->exit_statuses[i]))
	{
		stru->exit_statuses[i] = WEXITSTATUS(stru->exit_statuses[i]);
		stru->flag = stru->exit_statuses[i];
	}
	else if (WIFSTOPPED(stru->exit_statuses[i]))
	{
		stru->exit_statuses[i] = WSTOPSIG(stru->exit_statuses[i]) + 128;
		stru->flag = stru->exit_statuses[i];
	}
	i++;
	return (i);
}

void	subprocesses(int len, char **reassembled_commands, t_struct *stru)
{
	int	i;

	g_global_sig = 1;
	i = 0;
	stru->pipefds = create_pipes(len - 1);
	while (i < len)
	{
		stru->pids[i] = subprocess(i, reassembled_commands, stru, len);
		i++;
	}
	stru->pids[i] = -1;
	i = 0;
	close_fds(stru->pipefds, stru->filefds, stru->unused_fds, len);
	stru->exit_statuses = calloc(len +1, sizeof(int));
	signal(SIGINT, SIG_IGN);
	while (stru->pids[i] != -1)
		i = wait_loop(stru, i);
	if (stru->exit_statuses[i - 1] == 130 && (isatty(STDIN_FILENO)))
		write (STDOUT_FILENO, "\n", 1);
	signal(SIGINT, sigint_handler_default);
	stru->exit_statuses[i] = 0;
	stru->exit_status = stru->exit_statuses[i -1];
}

pid_t	subprocess(int pos, char **reassembled_commands, \
						t_struct *stru, int len)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup_io(stru->pipefds, stru->filefds, reassembled_commands, pos);
		close_fds(stru->pipefds, stru->filefds, stru->unused_fds, len);
		mod_execve(reassembled_commands[pos], stru->env_copy, stru);
		perror_exit("child process failed");
	}
	return (pid);
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

void	close_fds(int **pipefds, int (*filefds)[2] \
, int unused_fds[8192], int len)
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
