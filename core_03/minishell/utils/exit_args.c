/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 21:34:45 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/30 18:19:28 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	throw_error(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] == ' ' || arg[i] == '\t')
		i++;
	while (ft_isdigit(arg[i]))
		i++;
	while (arg[i] != 0)
	{
		if (arg[i] != ' ' && arg[i] != '\t')
		{
			write(2, "argument error: exited with invalid arguments\n", 47);
			return ;
		}
		i++;
	}
}

void	set_exit_code(t_struct *stru, char *arg)
{
	if (arg[0] == '-')
	{
		stru->exit_code = 256 + ft_atoi(arg + 1) * -1;
	}
	else if (arg[0] == '+' || arg[0] == '-')
	{
		stru->exit_code = ft_atoi(arg + 1);
	}
	else
	{
		stru->exit_code = ft_atoi(arg);
	}
}

void	exit_with_arg(t_struct *stru, char *arg)
{
	int		i;
	int		j;
	int		n;
	char	*exitcode_str;

	exitcode_str = malloc(sizeof(char) * 4);
	n = 3;
	i = 0;
	j = 0;
	while (arg[i] == ' ' || arg[i] == '\t')
		i++;
	while (ft_isdigit(arg[i]) && n > 0)
	{
		exitcode_str[j++] = arg[i++];
		n--;
	}
	exitcode_str[i] = '\0';
	set_exit_code(stru, exitcode_str);
}
