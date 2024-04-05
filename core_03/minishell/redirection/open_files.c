/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:38:29 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 06:38:29 by dgacic           ###   ########.fr       */
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
			printf("\nError opening file\n");
			return ;
		}
	}
	else
		printf("\nno file after <");
}

void	ft_append(t_struct *stru, int i, int index)
{
	if (stru->split_by_space[i + 1])
	{
		if (stru->filefds[index][1] != 0)
		{
			stru->unused_fds[stru->ufd_i++] = stru->filefds[index][1];
		}
		stru->filefds[index][1] \
		= open(stru->split_by_space[i + 1], \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (stru->filefds[index][1] == -1)
		{
			printf("Error opening file\n");
			return ;
		}
	}
	else
		printf("\nno file after >> ");
}

void	ft_outfile(t_struct *stru, int i, int index)
{
	if (stru->split_by_space[i + 1])
	{
		if (stru->filefds[index][1] != 0)
		{
			printf("\nfd to unused");
			stru->unused_fds[stru->ufd_i++] = stru->filefds[index][1];
		}
		stru->filefds[index][1] \
		= open(stru->split_by_space[i + 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (stru->filefds[index][1] == -1)
		{
			printf("Error opening file\n");
			return ;
		}
	}
	else
		printf("\nno file after > ");
}

void	open_files(t_struct *stru, int index)
{
	int	i;

	i = 0;
	while (stru->split_by_space[i])
	{
		if (ft_strncmp(stru->split_by_space[i], "<<", 2) == 0)
			ft_heredoc(index, stru, stru->split_by_space[i + 1]);
		else if (stru->split_by_space[i][0] == '<')
			ft_infile(stru, i, index);
		if (ft_strncmp(stru->split_by_space[i], ">>", 2) == 0)
			ft_append(stru, i, index);
		else if (stru->split_by_space[i][0] == '>')
			ft_outfile(stru, i, index);
		i++;
	}
}

void	terminate_filefds(t_struct *stru, int index)
{
	stru->unused_fds[stru->ufd_i] = -1;
	stru->filefds[index][0] = -1;
	stru->filefds[index][1] = -1;
}
