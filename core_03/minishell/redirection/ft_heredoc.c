/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:19:51 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/04 17:36:09 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_heredoc_line(t_struct *stru, int heredoc_fd, char *delimiter)
{
	stru->line = readline("heredoc ## ");
	while (stru->line != NULL && g_global_sig != 4)
	{
		if (ft_strcmp(stru->line, "") == 0)
		{
			write(heredoc_fd, "\n", 1);
		}
		else if (ft_strcmp(stru->line, delimiter) == 0)
		{
			free(stru->line);
			break ;
		}
		else
		{
			write(heredoc_fd, stru->line, ft_strlen(stru->line));
			write(heredoc_fd, "\n", 1);
			free(stru->line);
		}
		stru->line = readline("heredoc ## ");
	}
}

int	ft_heredoc(int index, t_struct *stru, char *delimiter)
{
	const char	*filename = "heredoc_out.txt";
	int			heredoc_fd;

	heredoc_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (heredoc_fd == -1)
	{
		perror("Error opening heredoc");
		return (1);
	}
	g_global_sig = 2;
	process_heredoc_line(stru, heredoc_fd, delimiter);
	close(heredoc_fd);
	heredoc_fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	stru->filefds[index][0] = heredoc_fd;
	g_global_sig = 0;
	return (0);
}

/* int	ft_heredoc(int index, t_struct *stru, char *delimiter)
{
	const char	*filename = "heredoc_out.txt";
	int			heredoc_fd;

	heredoc_fd = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (heredoc_fd == -1) 
	{
		perror("Error opening heredoc");
		return (1);
	}
	g_global_sig = 2;
	while ((stru->line = readline("heredoc ## ")) != NULL && g_global_sig != 4)
	{
		if (strcmp(stru->line, "") == 0)
		{
			write(heredoc_fd, "\n", 1);
			continue ;
		}
		if (strcmp(stru->line, delimiter) == 0)
		{
			free(stru->line);
			break ;
		}
		write(heredoc_fd, stru->line, ft_strlen(stru->line));
		write(heredoc_fd, "\n", 1);
		free(stru->line);
	}
	close (heredoc_fd);
	heredoc_fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	stru->filefds[index][0] = heredoc_fd;
	g_global_sig = 0;
	return (0);
} */
