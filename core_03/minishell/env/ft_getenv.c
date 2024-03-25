/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:19:00 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/25 12:23:21 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_getenv(const char *varname, char **env_copy)
{
	char	*current;
	int		i;

	i = 0;
	while (env_copy[i] != NULL) 
	{
		current = env_copy[i];
		if (ft_strncmp(varname, current, strlen(varname)) == 0 && current[strlen(varname)] == '=')
		{
			return (&current[strlen(varname) + 1]);
		}
		i++;
	}
	printStringArray(env_copy);
	return (NULL);
}
