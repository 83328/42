/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:35:14 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/30 21:49:04 by alimpens         ###   ########.fr       */
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

char	*get_var(const char *input)
{
	const char	*equal_sign;
	size_t		val_length;
	char		*val; 

	equal_sign = strchr(input, '=');
	if (equal_sign == NULL)
		return (NULL);
	val_length = equal_sign - input;
	val = (char *) malloc((val_length + 1) * sizeof(char));
	if (val == NULL)
		return (NULL);
	strncpy(val, input, val_length);
	val[val_length] = '\0';
	return (val);
}

void	export_command(t_struct *stru, char **args)
{
	int		i;
	char	*value;
	char	*var;

	i = 1;
	while (args[i] != NULL)
	{
		value = ft_strdup(args[i]);
		var = get_var(value);
		if (!one_equal(value) || !alnum_or_equal(value))
		{
			write(2, "wrong export args\n", 19);
			free(value);
			stru->exit_status = 1;
		}
		else
		{
			if (ft_getenv(var, stru->env_copy) != NULL)
				unset(stru->env_copy, var);
			export_set(value, stru);
		}
		free(var);
		i++;
	}
}

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
