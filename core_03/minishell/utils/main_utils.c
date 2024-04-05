/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:37:25 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 17:41:15 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_struct	*startup(int argc, char *argv[], char *envp[], t_struct *stru)
{
	(void)argc;
	(void)argv;
	stru = ft_calloc(1, sizeof(t_struct));
	stru->ufd_i = 0;
	copy_env(envp, stru);
	signal_handling();
	stru->exit_status = 0;
	set("?", "0", stru);
	stru->exit_code = 0;
	return (stru);
}

void	calloc_comms(t_struct *stru, int len)
{
	stru->reassembled_commands = ft_calloc((len + 1 + 1), sizeof(char *));
	stru->filefds = ft_calloc((2 * len) + 2, sizeof(int ));
	stru->pids = ft_calloc(len + 1, sizeof(pid_t));
}

void	parse_commands(t_struct *stru, t_vars *vars)
{
	stru->input_by_pipes = pipe_split(stru->input);
	while (stru->input_by_pipes[vars->len])
		vars->len++;
	calloc_comms(stru, vars->len);
	while (stru->input_by_pipes[vars->i])
	{
		stru->split_by_space = space_split(stru->input_by_pipes[vars->i]);
		open_files(stru, vars->i);
		rem_redir(stru->split_by_space);
		vars->k = 0;
		while (stru->split_by_space[vars->k])
			vars->k++;
		stru->reassembled_commands[vars->j] = \
		line_expansion(concat_strings(stru->split_by_space, vars->k), stru);
		if (stru->reassembled_commands[vars->j] == NULL)
			break ;
		vars->i++;
		vars->j++;
		free_2d(stru->split_by_space);
		free(stru->split_by_space);
	}
	terminate_filefds(stru, vars->i);
}

void	builtin_or_commands(t_struct *stru, t_vars *vars)
{
	char	**split_command;

	if (ft_strncmp(stru->reassembled_commands[0], "cd", 2) == 0 && vars->i == 1)
	{
		split_command = ft_split(stru->reassembled_commands[0], ' ');
		cd_command(stru, split_command);
		free(split_command);
	}
	else if (ft_strncmp(stru->reassembled_commands[0], "export", 6) == 0)
	{
		export_command(stru->reassembled_commands[1], stru);
	}
	else
	{
		g_global_sig = 1;
		subprocesses(vars->len, stru->reassembled_commands, stru);
	}
	g_global_sig = 0;
	unset(stru->env_copy, "?");
	stru->str = ft_itoa(stru->exit_status);
	set("?", stru->str, stru);
}

void	exit_parse(t_struct *stru)
{
	if (ft_strncmp(stru->input, "exit ", 5) == 0 \
	|| ft_strcmp(stru->input, "exit") == 0)
	{
		if (stru->input[5] != '\0')
		{
			if (stru->input[5] == ' ' || !ft_isdigit(stru->input[5]))
			{
				dprintf(2, "exit: %s numeric argument required\n" \
				, stru->input + 5);
				stru->exit_code = 0;
			}
			else
				stru->exit_code = ft_atoi(stru->input + 5);
		}
		dprintf(2, "exit\n");
		exit(stru->exit_code);
	}
}
