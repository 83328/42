/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:34:57 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/08 21:34:57 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_env(char *envp[], t_struct *str)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	if (str->env_copy)
	{
		free_2d(str->env_copy);
	}
	while (envp[size] != NULL)
	{
		size++;
	}
	str->env_copy_size = size + 1;
	str->env_copy = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		str->env_copy[i] = ft_strdup(envp[i]);
		i++;
	}
	str->env_copy[size] = NULL;
}

/* void	copy_env(char *envp[], t_struct *str)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (envp[size] != NULL)
		size++;
	str->env_copy_size = size + 1;
	str->env_copy = ft_calloc((size + 1),(sizeof(char*)));
	str->env_copy = copy_2d(envp, str->env_copy);
} */