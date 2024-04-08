/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:33 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/07 15:43:38 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	echo_command(char *str)
{
	int	i;
	int	print_newline;

	i = 4;
	print_newline = 1;
	if (ft_strncmp(str, "echo", 4) == 0)
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;
		if (ft_strncmp(&str[i], "-n", 2) == 0)
		{
			print_newline = 0;
			i += 2;
		}
		while (str[i] == ' ' || str[i] == '\t')
			i++;
	}
	if (str[i] != '\0')
	{
		printf("%s", &str[i]);
	}
	if (print_newline)
	{
		printf("\n"); 
	}
}
