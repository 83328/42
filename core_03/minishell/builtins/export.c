/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:35:14 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/12 14:04:33 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	shift_env_copy(char **env_copy, int start_index)
{
	int	i;

	i = start_index;
	while (env_copy[i])
	{
		env_copy[i] = env_copy[i + 1];
		i++;
	}
}

void	export_command(t_struct *stru, char **args)
{
	int	i;

	i = 1;
	if (args == NULL)
	{
		return ;
	}
	if (args[i] == NULL)
	{
		return ;
	}
	while (args[i])
	{
		if (!is_valid_identifier(args[i]))
		{
			write(2, "export: `", 9);
			write(2, args[i], strlen(args[i]));
			write(2, "`: not a valid identifier\n", 27);
			stru->exit_status = 1;
			return ;
		}
		handle_existing_var(stru, args[i]);
		i++;
	}
}

/* void	export_command(t_struct *stru, char **args)
{
	char	*new_var;
	int		i;

	if (args == NULL || args[1] == NULL)
		return ;
	i = 0;
	new_var = args[1];
	if (!new_var)
	{
		fprintf(stderr, "Memory allocation failed \n");
		return ;
	}
	while (stru->env_copy[i])
		i++;
	handle_new_var(stru, new_var, i);
} */

/* void	export_command(t_struct *stru, char **args)
{
	char	*new_var;
	int		i;

	if (args == NULL || args[1] == NULL)
		return ;
	i = 0;
	new_var = args[1];
	if (!new_var)
	{
		fprintf(stderr, "Memory allocation failed \n");
		return ;
	}
	while (stru->env_copy[i])
		i++;
	if (i >= stru->env_copy_size - 1)
	{
		resize_env_copy(stru);
		if (!stru->env_copy)
		{
			free(new_var);
			fprintf(stderr, "Memory allocation failed \n");
			return ;
		}
	}
	stru->env_copy[i] = new_var;
	stru->env_copy[i + 1] = NULL;
} */

void	resize_env_copy(t_struct *stru)
{
	int	old_size;
	int	i;

	old_size = stru->env_copy_size;
	stru->env_copy_size = stru->env_copy_size * 2;
	stru->env_copy = char2d_realloc(stru->env_copy, \
			stru->env_copy_size, old_size);
	i = old_size;
	while (i < stru->env_copy_size)
	{
		stru->env_copy[i] = NULL;
		i++;
	}
}

char	**char2d_realloc(char **ptr, int new_size, int old_size)
{
	char	**ret;
	int		i;

	i = 0;
	ret = ft_calloc(new_size, sizeof(char *));
	if (ret == NULL)
		perror_exit("calloc failed in char2d_realloc");
	if (ptr == NULL)
		perror_exit("pointer NULL fail in char2d");
	if (!new_size)
		perror_exit("no size fail in char2d");
	while (i < old_size && i < new_size)
	{
		ret[i] = ptr[i];
		i++;
	}
	if (ptr != NULL)
		free(ptr);
	return (ret);
}
