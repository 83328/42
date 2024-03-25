/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:39:20 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/25 16:56:29 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* void    free_2d(char **array)
{
		int i;

		i = 0;
		while (array[i])
		{
				free(array[i]);
				i++;
		}
		free(array);
} */

int ft_array_len(char **array)
{
		int i;

		i = 0;
		while (array[i])
				i++;
		return (i);
}

char	**remove_from_2d(char **array, int index)
{
		int		i;
		char	**new_array;

		i = 0;
		new_array = malloc(sizeof(char *) * (ft_array_len(array)));
		if (!new_array)
				return (NULL);
		
		while (i < index)
		{
				new_array[i] = ft_strdup(array[i]);
				i++;
		}
		i++;
		while (array[i])
		{
				new_array[i-1] = ft_strdup(array[i]);
				i++;
		}
		new_array[i-1] = NULL; 
		free_2d(array);
		return (new_array);
}
