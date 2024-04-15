/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:34:57 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/12 14:03:16 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set(char *name, char *value, t_struct *stru)
{
	char	*equ;
	char	*val_dup;
	char	*new_var;
	int		i;

	if (ft_getenv(name, stru->env_copy) != NULL)
		unset(stru->env_copy, "?");
	equ = ft_strdup("=");
	new_var = ft_strdup(name);
	val_dup = ft_strdup(value);
	new_var = ft_concat(new_var, equ);
	new_var = ft_concat(new_var, val_dup);
	i = 0;
	while (stru->env_copy[i])
	{
		i++;
		if (i + 1 >= stru->env_copy_size)
			resize_env_copy(stru);
	}
	stru->env_copy[i] = ft_strdup(new_var);
	i++;
	stru->env_copy[i] = NULL;
	free(new_var);
}
