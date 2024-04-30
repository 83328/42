/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:24:05 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/30 16:25:42 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	calloc_comms(t_struct *stru, int len)
{
	stru->reassembled_commands = ft_calloc((len + 1 + 1), sizeof(char *));
	stru->filefds = ft_calloc((2 * len) + 2, sizeof(int ));
	stru->pids = ft_calloc(len + 1, sizeof(pid_t));
}

void	file_ops(t_struct *stru, t_vars *vars)
{
	open_files_nospace(stru, vars->i);
	open_files(stru, vars->i);
	rem_redir(stru->split_by_space);
	rem_redir_nospaces(stru->split_by_space);
}

int	parse_commands(t_struct *stru, t_vars *vars)
{
	stru->input = reduce_quotes(stru->input);
	stru->input_by_pipes = pipe_split(stru->input);
	free(stru->input);
	while (stru->input_by_pipes[vars->len])
		vars->len++;
	calloc_comms(stru, vars->len);
	while (stru->input_by_pipes[vars->i])
	{
		stru->split_by_space = space_split(stru->input_by_pipes[vars->i]);
		file_ops(stru, vars);
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
	return (check_for_empty_comms(stru->reassembled_commands));
}

void	process_command(t_struct *stru, int command_flag)
{
	char	**split_command;
	char	*home_path;

	split_command = ft_split(stru->reassembled_commands[0], ' ');
	if (command_flag == 1)
	{
		cd_command(stru, split_command);
	}
	else if (command_flag == 2)
	{
		export_command(stru, split_command);
	}
	else if (command_flag == 3)
	{
		home_path = getenv("HOME");
		if (home_path != NULL)
			chdir(home_path);
		else
			printf("cd: HOME not set\n");
	}
	free(split_command);
}

/* void	process_command(t_struct *stru, int command_flag)
{
	char	**split_command;

	split_command = ft_split(stru->reassembled_commands[0], ' ');
	if (command_flag == 1)
		cd_command(stru, split_command);
	else if (command_flag == 2)
		export_command(stru, split_command);
	else
	{
		write(2, split_command[0], strlen(split_command[0]));
		write(2, ": command not found\n", 20);
		stru->exit_status = 1;
	}
	free(split_command);
} */
