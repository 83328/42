/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:18:46 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/24 19:19:55 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**copy_2d(char **envp, char **envp_copy)
{
	int	count;
	int	i;

	count = 0;
	while (envp[count] != NULL)
		count++;
	i = 0;
	while (i < count)
	{
		envp_copy[i] = strdup(envp[i]);
		if (envp_copy[i] == NULL)
			perror_exit("Memory allocation error");
		i++;
	}
	envp_copy[i] = NULL;
	return (envp_copy);
}
