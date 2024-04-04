/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:39:48 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/04 16:38:47 by alimpens         ###   ########.fr       */
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
	signal(SIGINT, sigint_handler_heredoc);
	while ((stru->line = readline("heredoc ## ")) != NULL && g_global_sig == 0)
	{
		if (ft_strcmp(stru->line, "") == 0)
		{
			write(heredoc_fd, "\n", 1);
			continue ;
		}
		if (ft_strcmp(stru->line, delimiter) == 0)
		{
			free(stru->line);
			break ;
		}
		write(heredoc_fd, stru->line, ft_strlen(stru->line));
		write(heredoc_fd, "\n", 1);
		free(stru->line);
	}
	signal(SIGINT, sigint_handler_default);
	close(heredoc_fd);
	heredoc_fd = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);
	stru->filefds[index][0] = heredoc_fd;
	//close(heredoc_fd);
	//free(line);
	g_global_sig = 0;
	return (0);
}

void	open_files(t_struct *stru, int index)
{
	int	i;

	i = 0;
	while (stru->split_by_space[i])
	{
		if (ft_strncmp(stru->split_by_space[i], "<<", 2) == 0)
		{
			ft_heredoc(index, stru, stru->split_by_space[i + 1]);
		}
		else if (stru->split_by_space[i][0] == '<')
		{
			if (stru->split_by_space[i + 1])
			{
				if (stru->filefds[index][0] != 0)
					stru->unused_fds[stru->ufd_i++] = stru->filefds[index][0];
				stru->filefds[index][0] = open(stru->split_by_space[i + 1], O_RDONLY);
				if (stru->filefds[index][0] == -1)
				{
					printf("\nError opening file\n");
					return ;
				}
			}
			else
				printf("\nno file after <");
		}
		if (ft_strncmp(stru->split_by_space[i], ">>", 2) == 0)
		{
			if (stru->split_by_space[i + 1])
			{
				if (stru->filefds[index][1] != 0)
				{
					stru->unused_fds[stru->ufd_i++] = stru->filefds[index][1];
				}
				stru->filefds[index][1] = open(stru->split_by_space[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
				if (stru->filefds[index][1] == -1)
				{
					printf("Error opening file\n");
					return ;
				}
			}
			else
				printf("\nno file after >> ");
		}
		else if (stru->split_by_space[i][0] == '>')
		{
			if (stru->split_by_space[i + 1])
			{
				if (stru->filefds[index][1] != 0)
				{
					printf("\nfd to unused");
					stru->unused_fds[stru->ufd_i++] = stru->filefds[index][1];
				}
				stru->filefds[index][1] = open(stru->split_by_space[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (stru->filefds[index][1] == -1)
				{
					printf("Error opening file\n");
					return ;
				}
			}
			else
				printf("\nno file after > ");
		}
		i++;
	}
}

void	terminate_filefds(t_struct *stru, int index)
{
	stru->unused_fds[stru->ufd_i] = -1;
	stru->filefds[index][0] = -1;
	stru->filefds[index][1] = -1;
}
