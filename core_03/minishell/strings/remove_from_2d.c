/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_from_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:37:43 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 06:37:43 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* void	free_2d(char **array)
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

int	ft_array_len(char **array)
{
	int	i;

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
		new_array[i -1] = ft_strdup(array[i]);
		i++;
	}
	new_array[i -1] = NULL; 
	free_2d(array);
	return (new_array);
}
