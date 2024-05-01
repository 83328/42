/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:33:41 by dgacic            #+#    #+#             */
/*   Updated: 2024/05/01 12:54:57 by alimpens         ###   ########.fr       */
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
		while (s->env_copy[i])
		{
			free(s->env_copy[i]);
			s->env_copy[i] = NULL;
			i++;
		}
		free(s->env_copy);
		s->env_copy = NULL;
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
		s->split_by_space = NULL;
	}
}

void	free_malloced(char *line, char *cop_line)
{
	free(line);
	free(cop_line);
	cop_line = NULL;
}
