/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 13:36:20 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/11 15:57:36 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_valid_identifier(char *arg)
{
	int	i;

	if (!arg || (!isalpha(arg[0]) && arg[0] != '_'))
		return (0);
	i = 1;
	while (arg[i] && arg[i] != '=')
	{
		if (!isalnum(arg[i]) && arg[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

void	handle_new_var(t_struct *stru, char *new_var, int i)
{
	if (i >= stru->env_copy_size - 1)
	{
		resize_env_copy(stru);
		if (!stru->env_copy)
		{
			free(new_var);
			write(2, "Memory allocation failed \n", 27);
			return ;
		}
	}
	stru->env_copy[i] = new_var;
	stru->env_copy[i + 1] = NULL;
}

void	handle_existing_var(t_struct *stru, char *new_var)
{
	int		i;
	char	*var_name;

	i = 0;
	var_name = strtok(strdup(new_var), "=");
	while (stru->env_copy[i])
	{
		if (strncmp(stru->env_copy[i], var_name, strlen(var_name)) == 0 \
			&& stru->env_copy[i][strlen(var_name)] == '=')
		{
			free(stru->env_copy[i]);
			stru->env_copy[i] = strdup(new_var);
			free(var_name);
			return ;
		}
		i++;
	}
	free(var_name);
	handle_new_var(stru, new_var, i);
}
