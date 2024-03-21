/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 17:21:33 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/20 16:51:56 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* int echo_command(int ac, char *av[])
{
	int no_newline = 0;
	int i;

	i = 1;
	if (ac > 1 && ft_strcmp(av[1], "-n") == 0)
	{
		no_newline = 1;
		i++;
	}
	while (i < ac)
	{
		printf("%s", av[i]);
		if (i < ac - 1)
			printf(" ");
		i++;
	}
	if (!no_newline)
		printf("\n");
	return (0);
} */

/* int echo_command(char *command)
{
	int has_n;
	char *to_echo;
	
	to_echo = malloc(sizeof(char) * ft_strlen(command) + 1);
	has_n = checks_n(command);
	remove_echo(command, has_n);
	if (has_n == 0)
	{
		
	}
	else
		command = command + 1;
}

int remove_echo()
{
	
} */

void echo_command(char *str)
{
	int i;
	int j;
	int print_newline;

	i = 4;
	j = 0; 
	print_newline = 1;
	if (strncmp(str, "echo", 4) == 0)
	{
		if (str[i] == ' ' || str[i] == '\t')
		i++;
		if (strncmp(&str[i], "-n", 2) == 0)
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