/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:23 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/04 14:45:51 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	shift_env_array(char **env_cp, int start_index)
{
	int	j;

	j = start_index;
	while (env_cp[j] != NULL)
	{
		env_cp[j] = env_cp[j + 1];
		j++;
	}
}

int	unset(char **env_cp, const char *varname)
{
	int	i;

	i = 0;
	while (env_cp[i] != NULL)
	{
		if (ft_strncmp(env_cp[i], varname, 
				ft_strlen(varname)) == 0 && 
			env_cp[i][ft_strlen(varname)] == '=')
		{
			free(env_cp[i]);
			shift_env_array(env_cp, i);
			return (0);
		}
		i++;
	}
	return (1);
}

/* int	unset(char **env_cp, const char *varname)
{
	int	i;
	int	j;
	int	env_count;

	env_count = 0;
	i = 0;
	while (env_cp[env_count] != NULL)
		env_count++;
	while (i < env_count)
	{
		if (strncmp(env_cp[i], varname, 
				ft_strlen(varname)) == 0 && env_cp[i][ft_strlen(varname)] == '=')
		{
			free(env_cp[i]);
			j = i;
			while (j < env_count - 1)
			{
				env_cp[j] = env_cp[j + 1];
				j++;
			}
			env_cp[j] = NULL;
			return (0);
		}
		i++;
	}
	return (1);
} */
