/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_processing.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 10:24:05 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/10 10:24:23 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	calloc_comms(t_struct *stru, int len)
{
	stru->reassembled_commands = ft_calloc((len + 1 + 1), sizeof(char *));
	stru->filefds = ft_calloc((2 * len) + 2, sizeof(int ));
	stru->pids = ft_calloc(len + 1, sizeof(pid_t));
}

int	parse_commands(t_struct *stru, t_vars *vars)
{
	stru->input = reduce_quotes(stru->input);
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
	return (check_for_empty_comms(stru->reassembled_commands));
}

void	process_command(t_struct *stru, int command_flag)
{
	char	**split_command;

	split_command = ft_split(stru->reassembled_commands[0], ' ');
	if (command_flag == 1)
		cd_command(stru, split_command);
	else if (command_flag == 2)
		export_command(stru, split_command);
	free(split_command);
}
