/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:31:33 by dgacic            #+#    #+#             */
/*   Updated: 2024/05/01 12:23:03 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_struct	*startup(int argc, char *argv[], char *envp[], t_struct *stru)
{
	(void)argc;
	(void)argv;
	stru = ft_calloc(1, sizeof(t_struct));
	stru->exit_statuses = NULL;
	stru->ufd_i = 0;
	copy_env(envp, stru);
	signal_handling();
	stru->exit_status = 0;
	set("?", "0", stru);
	stru->exit_code = 0;
	return (stru);
}

void	block1(t_struct *stru, t_vars *vars)
{
	{
		g_global_sig = 1;
		subprocesses(vars->len, stru->reassembled_commands, stru);
	}
}

void	block2(t_struct *stru)
{
	{
		g_global_sig = 0;
		unset(stru->env_copy, "?");
		stru->str = ft_itoa(stru->exit_status);
		set("?", stru->str, stru);
	}
}

void	process_cd_command(t_struct *stru)
{
	if (ft_strlen(stru->reassembled_commands[0]) > 2 \
		&& stru->reassembled_commands[0][2] != ' ')
	{
		fprintf(stderr, "Error: Invalid command\n");
		return ;
	}
	if (ft_strlen(stru->reassembled_commands[0]) == 2)
		process_command(stru, 3);
	else
		process_command(stru, 1);
}

void	builtin_or_commands(t_struct *stru, t_vars *vars)
{
	char	**split_command;

	if (ft_strncmp(stru->reassembled_commands[0], "cd", 2) == 0 \
		&& vars->i == 1)
	{
		process_cd_command(stru);
	}
	else if (ft_strncmp(stru->reassembled_commands[0], "export ", 7) == 0)
		process_command(stru, 2);
	else if (ft_strncmp(stru->reassembled_commands[0], "unset ", 6) == 0)
	{
		split_command = NULL;
		split_command = ft_split(stru->reassembled_commands[0], ' ');
		unset(stru->env_copy, split_command[1]);
		free_2d(split_command);
		free(split_command);
		return ;
	}
	else
		block1(stru, vars);
	block2(stru);
}
