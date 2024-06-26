/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:35:14 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/09 14:27:48 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	printenv(char **strArray)
{
	int	i;

	i = 0;
	while (strArray[i] != NULL)
	{
		printf("\n%s", strArray[i]);
		i++;
	}
	printf("\n");
}

void	env_command(t_struct *stru)
{
	printenv(stru->env_copy);
}
