/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:33 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/04 14:35:22 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_command(char *str)
{
	int	i;
	int	j;
	int	print_newline;

	i = 4;
	j = 0;
	print_newline = 1;
	if (ft_strncmp(str, "echo", 4) == 0)
	{
		if (str[i] == ' ' || str[i] == '\t')
			i++;
		if (ft_strncmp(&str[i], "-n", 2) == 0)
		{
			print_newline = 0;
			i += 2;
		}
	}
	str = &str[i];
	printf("%s", str);
	if (print_newline)
	{
		printf("\n"); 
	}
}
