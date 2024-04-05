/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:39:21 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 06:39:21 by dgacic           ###   ########.fr       */
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
		if (ft_strncmp(varname, current, 
				ft_strlen(varname)) == 0 && current[ft_strlen(varname)] == '=')
		{
			return (&current[ft_strlen(varname) + 1]);
		}
		i++;
	}
	return (NULL);
}
