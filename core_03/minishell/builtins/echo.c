/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 02:21:12 by dgacic            #+#    #+#             */
/*   Updated: 2024/05/01 16:46:23 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_if_flag(char *string)
{
	int	flag_found;
	int	i;

	flag_found = 0;
	i = 0;
	while (string[i] != '\0')
	{
		while (string[i] == 'n')
			i++;
		if (string[i] == ' ' || string[i] == '\0')
			return (1);
		else
			return (0);
	}
	return (0);
}

void	echo_after_flags(char *str)
{
	int	n_count;

	while (*str != 0)
	{
		n_count = 0;
		if (*str != ' ' && *str != '-')
			break ;
		while (*str == ' ')
			str++;
		if (*str == '-')
			str++;
		while (*str == 'n')
		{
			str++;
			n_count++;
		}
		if (*str != ' ')
		{
			str = str - (n_count + 1);
			break ;
		}
		while (*str == ' ')
			str++;
	}
	ft_printf("%s", str);
}

void	echo_command(char *str)
{
	int		i;
	char	n;

	n = '\n';
	i = 5;
	if (ft_strcmp(str, "echo -n") == 0)
		return ;
	else if (ft_strncmp(str, "echo -n", 7) == 0)
	{
		if (check_if_flag(str + 6))
			echo_after_flags(str + 4);
		else
		{
			while (str[i] != '\0')
				write(1, &str[i++], 1);
			write(1, &n, 1);
		}
	}
	else if (ft_strncmp(str, "echo", 4) == 0)
	{
		while (str[i] != '\0')
			write(1, &str[i++], 1);
		write(1, &n, 1);
	}
}
