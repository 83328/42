/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:30:25 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/12 14:05:28 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_global_sig = 0;

void	set_null(t_struct *stru)
{
	stru->filefds = NULL;
	stru->pipefds = NULL;
	stru->str = NULL;
}

void	one_offs(t_struct *stru)
{
	exit_parse(stru);
	add_history(stru->input);
	init_vars(stru->vars);
	set_null(stru);
}

void	readline_and_check(t_struct *stru)
{
	stru->input = readline("minishell ## ");
	if (g_global_sig == 2)
		set("?", "130", stru);
}

void	shell_loop(t_struct *stru)
{
	stru->vars = malloc(sizeof(t_vars));
	while (1)
	{
		readline_and_check(stru);
		if (!stru->input)
		{
			write(2, "exit\n", 6);
			stru->exit_code = 2;
			break ;
		}
		if (ft_strcmp(stru->input, "") == 0)
			continue ;
		one_offs(stru);
		if (quote_errors(stru->input))
		{
			free(stru->input);
			set("?", "2", stru);
			continue ;
		}
		if (parse_commands(stru, stru->vars))
			continue ;
		builtin_or_commands(stru, stru->vars);
		free_loopend(stru, stru->vars->len);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	t_struct	*stru;

	stru = NULL;
	stru = startup(argc, argv, envp, stru);
	shell_loop(stru);
	free_exit(stru);
	return (0);
}
