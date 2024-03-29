/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:10 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/26 12:11:57 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	printenv(char **strArray)
{
	int	i;

	i = 0;
	while (strArray[i] != NULL)
	{
		printf("\nstrArr[%d] #%s#", i, strArray[i]);
		i++;
	}
	printf("\n");
}

void	env_command(t_struct *stru)
{
	printenv(stru->env_copy);
}
