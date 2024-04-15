/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_nospace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:58:28 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/12 13:59:00 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_infile_nospace(t_struct *stru, int i, int index)
{
	if (stru->split_by_space[i][1])
	{
		if (stru->filefds[index][0] != 0)
			stru->unused_fds[stru->ufd_i++] = stru->filefds[index][0];
		stru->filefds[index][0] \
		= open(&stru->split_by_space[i][1], O_RDONLY);
		if (stru->filefds[index][0] == -1)
		{
			printf("Error opening file\n");
			return ;
		}
	}
}

void	ft_append_nospace(t_struct *stru, int i, int index)
{
	int	file_descriptor;

	if (stru->split_by_space[i][2])
	{
		if (stru->filefds[index][1] != 0)
		{
			stru->unused_fds[stru->ufd_i++] = stru->filefds[index][1];
		}
		file_descriptor = open(&stru->split_by_space[i][2], \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
		stru->filefds[index][1] = file_descriptor;
		if (stru->filefds[index][1] == -1)
		{
			printf("Error opening file\n");
			return ;
		}
	}
}

void	ft_outfile_nospace(t_struct *stru, int i, int index)
{
	if (stru->split_by_space[i][1])
	{
		if (stru->filefds[index][1] != 0)
		{
			printf("fd to unused\n");
			stru->unused_fds[stru->ufd_i++] = stru->filefds[index][1];
		}
		stru->filefds[index][1] \
		= open(&stru->split_by_space[i][1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (stru->filefds[index][1] == -1)
		{
			printf("Error opening file\n");
			return ;
		}
	}
}

void	open_files_nospace(t_struct *stru, int index)
{
	int	i;

	i = 0;
	while (stru->split_by_space[i])
	{
		if (ft_strncmp(stru->split_by_space[i], "<<", 2) 
			== 0 && stru->split_by_space[i][2] != 0)
		{
			ft_heredoc(index, stru, &stru->split_by_space[i][2]);
		}
		else if (ft_strncmp(stru->split_by_space[i], "<", 1) 
			== 0 && stru->split_by_space[i][1] != '<')
		{
			ft_infile_nospace(stru, i, index);
		}
		if (ft_strncmp(stru->split_by_space[i], ">>", 2) == 0)
		{
			ft_append_nospace(stru, i, index);
		}
		else if (stru->split_by_space[i][0] == '>')
		{
			ft_outfile_nospace(stru, i, index);
		}
		i++;
	}
}
