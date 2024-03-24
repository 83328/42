/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_by_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:39:27 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/24 19:43:25 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		int_array_len(int *array)
{
	int i;

	i = 0;
	while (array[i] != -1)
		i++;
	return (i);
}

char	**split_by_index(char *input, int *real_indices)
{
	char **split_by_index;
	int i;
	int j;
	int start;
	int end;

	i = 0;
	j = 0;
	split_by_index = ft_calloc(int_array_len(real_indices) + 2, sizeof(char *));
	while (real_indices[i] != -1)
	{
		start = j;
		end = real_indices[i];
		split_by_index[i] = ft_substr(input, start, end - start);
		j = end + 1;
		i++;
	}
	start = j;
	end = real_indices[i];
	split_by_index[i] = ft_substr(input, start, end - start);
	i++;
	split_by_index[i] = NULL;
	return (split_by_index);
}
