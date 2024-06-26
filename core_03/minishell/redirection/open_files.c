/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:33:05 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/10 17:49:25 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_infile(t_struct *stru, int i, int index)
{
	if (stru->split_by_space[i + 1])
	{
		if (stru->filefds[index][0] != 0)
			stru->unused_fds[stru->ufd_i++] = stru->filefds[index][0];
		stru->filefds[index][0] \
		= open(stru->split_by_space[i + 1], O_RDONLY);
		if (stru->filefds[index][0] == -1)
		{
			printf("Error opening file\n");
			return ;
		}
	}
}

void	ft_append(t_struct *stru, int i, int index)
{
	int	file_descriptor;

	if (stru->split_by_space[i + 1])
	{
		if (stru->filefds[index][1] != 0)
		{
			stru->unused_fds[stru->ufd_i++] = stru->filefds[index][1];
		}
		file_descriptor = open(stru->split_by_space[i + 1], \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
		stru->filefds[index][1] = file_descriptor;
		if (stru->filefds[index][1] == -1)
		{
			printf("Error opening file\n");
			return ;
		}
	}
}

void	ft_outfile(t_struct *stru, int i, int index)
{
	if (stru->split_by_space[i + 1])
	{
		if (stru->filefds[index][1] != 0)
		{
			stru->unused_fds[stru->ufd_i++] = stru->filefds[index][1];
		}
		stru->filefds[index][1] \
		= open(stru->split_by_space[i + 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (stru->filefds[index][1] == -1)
		{
			return ;
		}
	}
}

void	open_files(t_struct *stru, int index)
{
	int	i;

	i = 0;
	while (stru->split_by_space[i])
	{
		if (ft_strcmp(stru->split_by_space[i], "<<") == 0)
		{
			ft_heredoc(index, stru, stru->split_by_space[i + 1]);
		}
		else if (ft_strcmp(stru->split_by_space[i], "<") == 0)
		{
			ft_infile(stru, i, index);
		}
		if (ft_strcmp(stru->split_by_space[i], ">>") == 0)
		{
			ft_append(stru, i, index);
		}
		else if (ft_strcmp(stru->split_by_space[i], ">") == 0)
		{
			ft_outfile(stru, i, index);
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
