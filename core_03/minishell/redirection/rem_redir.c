/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:39:54 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/26 14:27:48 by alimpens         ###   ########.fr       */
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
		if (split_by_spaces[i][0] == '<' || split_by_spaces[i][0] == '>' || strcmp(split_by_spaces[i], "<<") == 0 || strcmp(split_by_spaces[i], ">>") == 0)
		{
			rem_string(split_by_spaces, i + 1);
			rem_string(split_by_spaces, i);
			i = 0;
			continue ;
		}
		i++;
	}
}
