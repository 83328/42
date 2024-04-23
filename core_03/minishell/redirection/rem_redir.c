/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:33:05 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/12 14:05:52 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	rem_string(char **split_by_spaces, int index)
{
	int	i;

	i = index;
	while (split_by_spaces[i])
	{
		split_by_spaces[i] = split_by_spaces[i + 1];
		i++;
	}
}

void	rem_redir(char **split_by_spaces)
{
	int	i;

	i = 0;
	while (split_by_spaces[i])
	{
		if (ft_strcmp(split_by_spaces[i], "<") == 0 || \
			(ft_strcmp(split_by_spaces[i], ">") == 0 || \
			ft_strcmp(split_by_spaces[i], "<<") == 0 || \
			ft_strcmp(split_by_spaces[i], ">>") == 0))
		{
			free(split_by_spaces[i + 1]);
			rem_string(split_by_spaces, i + 1);
			free(split_by_spaces[i]);
			rem_string(split_by_spaces, i);
			i = 0;
			continue ;
		}
		i++;
	}
}

void	rem_redir_nospaces(char **split_by_spaces)
{
	int	i;

	i = 0;
	while (split_by_spaces[i])
	{
		if (ft_strncmp(split_by_spaces[i], "<", 1) == 0 || \
			ft_strncmp(split_by_spaces[i], ">", 1) == 0 || \
			ft_strncmp(split_by_spaces[i], "<<", 2) == 0 || \
			ft_strncmp(split_by_spaces[i], ">>", 2) == 0)
		{
			free(split_by_spaces[i]);
			rem_string(split_by_spaces, i);
			i = 0;
			continue ;
		}
		i++;
	}
}
