/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 10:24:17 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/15 17:20:45 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handle_exit_error(t_struct *stru, int space_count)
{
	if (space_count > 0)
	{
		write(2, "exit: too many arguments\n", 24);
		stru->exit_code = 1;
		return ;
	}
	write(2, " numeric argument required\n", 27);
	stru->exit_code = 0;
}

void	handle_arg(t_struct *stru, char *arg, int *i, int *space_count)
{
	while (arg[*i] != '\0')
	{
		if (!ft_isdigit(arg[*i]))
		{
			if (arg[*i] == ' ')
			{
				if (arg[*i + 1] == '\0')
					break ;
				(*space_count)++;
			}
			else if ((arg[*i] == '+' || arg[*i] == '-') && \
				ft_isdigit(arg[*i + 1]))
			{
				(*i)++;
			}
			else
			{
				handle_exit_error(stru, *space_count);
				break ;
			}
		}
		(*i)++;
	}
}

void	check_exit_args(t_struct *stru, char *arg)
{
	char	*new_arg;

	new_arg = remove_quotes(arg);
	throw_error(new_arg);
	exit_with_arg(stru, new_arg);
}

void	exit_parse(t_struct *stru)
{
	char	*arg;

	if (ft_strncmp(stru->input, "exit ", 5) == 0 \
	|| ft_strcmp(stru->input, "exit") == 0)
	{
		arg = stru->input + 5;
		while (*arg == ' ')
			arg++;
		check_exit_args(stru, arg);
		write(2, "exit\n", 6);
		exit(stru->exit_code);
	}
}
