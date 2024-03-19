/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:10 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/19 10:27:59 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* void env_command()
{
	extern char** environ;
	int i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++; 
	}
} */

void	env_command(char **env_copy)
{
		int i;
printf("xxxxxxxxxxxxxxxxxxxxxxxxxenv_commandxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
		i = 0;
		while (env_copy[i] != NULL)
		{
				ft_printf("\n%s", env_copy[i]);
				i++;
		}
		ft_printf("\n");
}
