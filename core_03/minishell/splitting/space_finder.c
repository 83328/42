/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_finder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 11:09:52 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/15 13:49:50 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_reduced_string(char *reduced_string, 
	int *real_space_indices, int *nth_space)
{
	int		i;
	char	flag;

	i = 0;
	while (reduced_string[i])
	{
		if (reduced_string[i] == '\"' || reduced_string[i] == '\'')
		{
			flag = reduced_string[i];
			i++;
			while (reduced_string[i] != flag)
				i++;
		}
		if (reduced_string[i] == ' ')
		{
			real_space_indices[*nth_space] = i;
			(*nth_space)++;
		}
		i++;
	}
}

int	*find_real_spaces(char *reduced_string)
{
	int	i;
	int	*real_space_indices;
	int	nth_space;
	int	num_spaces;

	i = 0;
	num_spaces = 0;
	while (reduced_string[i])
	{
		if (reduced_string[i] == ' ')
			num_spaces++;
		i++;
	}
	real_space_indices = ft_calloc(num_spaces + 1, sizeof(int));
	nth_space = 0;
	process_reduced_string(reduced_string, real_space_indices, &nth_space);
	real_space_indices[nth_space] = -1;
	return (real_space_indices);
}
