/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:37:25 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 14:10:15 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_2d(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i] != NULL)
		{
			free(array[i]);
			i++;
		}
	}
}

void	free_2dint(int **array, int len)
{
	int	i;

	i = 0;
	if (array)
	{
		while (i < len)
		{
			free(array[i]);
			i++;
		}
	}
}

void	free_env_copy(t_struct *s)
{
	int	i;

	i = 0;
	if (s->env_copy != NULL)
	{
		while (i < s->env_copy_size && s->env_copy[i] != NULL)
		{
			free(s->env_copy[i]);
			i++;
		}
		free(s->env_copy);
	}
}

void	free_split_by_space(t_struct *s)
{
	int	i;

	i = 0;
	if (s->split_by_space != NULL)
	{
		while (s->split_by_space[i] != NULL)
		{
			free(s->split_by_space[i]);
			i++;
		}
		free(s->split_by_space);
	}
}
