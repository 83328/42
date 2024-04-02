/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:06:15 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/01 19:14:03 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	env(char **env_cp)
{
	int	i;

	i = 0;
	while (env_cp[i] != NULL)
	{
		ft_printf("\nstrArr[%d] %s", i, env_cp[i]);
		i++;
	}
	ft_printf("\n");
}
