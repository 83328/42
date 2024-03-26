/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:19:51 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/26 14:33:28 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
	global_sig = 2;
	while ((stru->line = readline("heredoc ## ")) != NULL && global_sig != 4) // add delimiter flag
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
		write(heredoc_fd, stru->line, strlen(stru->line));
		write(heredoc_fd, "\n", 1);
		free(stru->line);
	}
	close (heredoc_fd);
	heredoc_fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	stru->filefds[index][0] = heredoc_fd;
//free(line);
	global_sig = 0;
	return (0);
}
