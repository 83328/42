/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:25:18 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/30 21:44:59 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	one_equal(const char *str)
{
	int	equal_sign_count;
	int	length;
	int	i;

	equal_sign_count = 0;
	length = strlen(str);
	i = 0;
	while (i < length)
	{
		if (str[i] == '=')
		{
			equal_sign_count++;
			if (equal_sign_count > 1)
				return (0);
		}
		i++;
	}
	if (equal_sign_count == 1)
		return (1);
	else
		return (0);
}

int	alnum_or_equal(const char *str)
{
	int	length;

	length = 0;
	while (str[length] != '\0')
	{
		if (!isalnum(str[length]) && str[length] != '=')
		{
			return (0);
		}
		length++;
	}
	return (1);
}

void	export_set(char *new_var, t_struct *stru)
{
	int		i;

	i = 0;
	if (!new_var)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return ;
	}
	while (stru->env_copy[i])
	{
		i++;
		if (i >= stru->env_copy_size - 1)
		{
			resize_env_copy(stru);
			if (!stru->env_copy)
			{
				free(new_var);
				fprintf(stderr, "Memory allocation failed\n");
				return ;
			}
		}
	}
	stru->env_copy[i] = new_var;
	stru->env_copy[i + 1] = NULL;
}
