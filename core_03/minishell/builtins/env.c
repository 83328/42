/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:10 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/24 14:32:43 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void    printenv(char **strArray)
{
    int i;

    i = 0;
    while (strArray[i] != NULL)
    {
        printf("\nstrArr[%d] #%s#", i ,strArray[i]);
        i++;
    }
    printf("\n");
}

void	env_command(t_struct *stru)
{
	printenv(stru->env_copy);
		// int i;
		
		// i = 0;
		// while (stru->env_copy != NULL)
		// {
		// 		ft_printf("\n%s", stru->env_copy[i]);
		// 		i++;
		// }
		// ft_printf("\n");
}
