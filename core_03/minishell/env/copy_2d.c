/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_2d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:39:21 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 06:39:21 by dgacic           ###   ########.fr       */
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
