/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:34:57 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/23 01:03:16 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_3(char *tmp, char *tmp2, char *new_var)
{
	free(tmp);
	free(tmp2);
	free(new_var);
}

void	free_2(char *tmp2, char *tmp_name)
{
	free(tmp2);
	free(tmp_name);
}

void	addvar_and_null(t_struct *stru, int i, char *new_var)
{
	stru->env_copy[i] = ft_strdup(new_var);
	i++;
	stru->env_copy[i] = NULL;
}

void	set(char *name, char *value, t_struct *stru)
{
	char	*tmp2;
	char	*tmp_name;
	char	*tmp;
	char	*new_var;
	int		i;

	if (ft_getenv(name, stru->env_copy) != NULL)
		unset(stru->env_copy, "?");
	tmp2 = ft_strdup("=");
	tmp_name = ft_strdup(name);
	tmp = ft_concat(tmp_name, tmp2);
	free_2(tmp2, tmp_name);
	tmp2 = ft_strdup(value);
	new_var = ft_concat(tmp, tmp2);
	i = 0;
	while (stru->env_copy[i])
	{
		i++;
		if (i + 1 >= stru->env_copy_size)
			resize_env_copy(stru);
	}
	addvar_and_null(stru, i, new_var);
	free_3(tmp, tmp2, new_var);
}
