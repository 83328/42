/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:06:19 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/01 19:13:26 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set(char *name, char *value, t_struct *stru)
{
	char	*equ;
	char	*val_dup;
	char	*new_var;
	int		i;

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
