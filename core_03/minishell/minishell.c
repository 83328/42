/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:30:25 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/10 22:32:00 by alimpens         ###   ########.fr       */
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

void	shell_loop(t_struct *stru)
{
	stru->vars = malloc(sizeof(t_vars));
	while (1)
	{
		stru->input = readline("minishell ## ");
		if (!stru->input)
		{
			write(2, "exit\n", 6);
			stru->exit_code = 2;
			break ;
		}
		if (ft_strcmp(stru->input, "") == 0)
			continue ;
		exit_parse(stru);
		if (quote_errors(stru->input))
		{
			free(stru->input);
			continue ;
		}
		add_history(stru->input);
		init_vars(stru->vars);
		set_null(stru);
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
