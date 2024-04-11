/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:35:14 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/08 21:35:14 by dgacic           ###   ########.fr       */
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
