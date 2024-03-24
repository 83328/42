/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:23 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/24 19:07:19 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	unset(char **env_cp, const char *varname)
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
		if (strncmp(env_cp[i], varname, ft_strlen(varname)) == 0 && env_cp[i][ft_strlen(varname)] == '=')
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
}
