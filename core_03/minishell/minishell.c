/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:37:05 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 17:33:56 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_global_sig = 0;

void	shell_loop(t_struct *stru)
{
	t_vars	*vars;

	vars = malloc(sizeof(t_vars));
	while (1)
	{
		stru->input = readline("minishell ## ");
		if (!stru->input)
		{
			dprintf(2, "exit\n");
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
		init_vars(vars);
		parse_commands(stru, vars);
		builtin_or_commands(stru, vars);
		free_loopend(stru, vars->len);
	}
	free(vars);
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
