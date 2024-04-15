/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:21:12 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/15 13:43:00 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_command(char *str)
{
	int		i;
	char	n;

	n = '\n';
	i = 5;
	if (ft_strcmp(str, "echo -n") == 0)
		return ;
	else if (ft_strncmp(str, "echo -n ", 8) == 0)
	{
		i += 3;
		while (str[i] != '\0')
			write(1, &str[i++], 1);
	}
	else if (ft_strncmp(str, "echo", 4) == 0)
	{
		while (str[i] != '\0')
			write(1, &str[i++], 1);
		write(1, &n, 1); 
	}
}
