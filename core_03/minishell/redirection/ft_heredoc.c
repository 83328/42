/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:33:05 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/10 17:52:32 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	heredoc_loop(t_struct *stru, int heredoc_fd, char *delimiter);

int	ft_heredoc(int index, t_struct *stru, char *delimiter)
{
	const char	*filename = "/tmp/heredoc_out.txt";
	int			heredoc_fd;

	heredoc_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (heredoc_fd == -1)
	{
		perror("Error opening heredoc");
		return (1);
	}
	signal(SIGINT, sigint_handler_heredoc);
	heredoc_loop(stru, heredoc_fd, delimiter);
	signal(SIGINT, sigint_handler_default);
	close(heredoc_fd);
	heredoc_fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	stru->filefds[index][0] = heredoc_fd;
	g_global_sig = 0;
	return (0);
}

void	heredoc_loop(t_struct *stru, int heredoc_fd, char *delimiter)
{
	stru->line = readline("heredoc ## ");
	while (stru->line != NULL && g_global_sig != 4)
	{
		if (strcmp(stru->line, "") == 0)
		{
			write(heredoc_fd, "\n", 1);
			free(stru->line);
			stru->line = readline("heredoc ## ");
			continue ;
		}
		if (strcmp(stru->line, delimiter) == 0)
		{
			free(stru->line);
			break ;
		}
		write(heredoc_fd, stru->line, strlen(stru->line));
		write(heredoc_fd, "\n", 1);
		free(stru->line);
		stru->line = readline("heredoc ## ");
	}
}
