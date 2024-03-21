/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:10 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/19 11:25:55 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env_command(t_struct *stru)
{
		int i;
		
		i = 0;
		while (stru->env_copy != NULL)
		{
				ft_printf("\n%s", stru->env_copy[i]);
				i++;
		}
		ft_printf("\n");
}
