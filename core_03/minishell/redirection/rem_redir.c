/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:38:29 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 06:38:29 by dgacic           ###   ########.fr       */
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
		if (split_by_spaces[i][0] == '<' || split_by_spaces[i][0] == '>' || 
				ft_strcmp(split_by_spaces[i], "<<") == 0 || 
					ft_strcmp(split_by_spaces[i], ">>") == 0)
		{
			rem_string(split_by_spaces, i + 1);
			rem_string(split_by_spaces, i);
			i = 0;
			continue ;
		}
		i++;
	}
}
