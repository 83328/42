/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:33:41 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/09 14:26:15 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_reassembled_commands(t_struct *s)
{
	int	i;

	i = 0;
	if (s->reassembled_commands != NULL)
	{
		while (s->reassembled_commands[i] != NULL)
		{
			free(s->reassembled_commands[i]);
			i++;
		}
		free(s->reassembled_commands);
	}
}

void	free_input_by_pipes(t_struct *s)
{
	int	i;

	i = 0;
	if (s->input_by_pipes != NULL)
	{
		while (s->input_by_pipes[i] != NULL)
		{
			free (s->input_by_pipes[i]);
			i++;
		}
		free(s->input_by_pipes);
	}
}

void	free_pipefds(t_struct *s)
{
	int	i;

	i = 0;
	if (s->pipefds != NULL)
	{
		while (s->pipefds[i] != NULL)
		{
			free(s->pipefds[i]);
			i++;
		}
		free(s->pipefds);
	}
}

void	free_single_pointers(t_struct *s)
{
	free(s->input);
	s->input = NULL;
	free(s->filefds);
	s->filefds = NULL;
	free(s->pids);
	s->pids = NULL;
	free(s->line);
	s->line = NULL;
	free(s->exit_statuses);
	s->exit_statuses = NULL;
	free(s->str);
	s->str = NULL;
}

void	free_exit(t_struct *stru)
{
	free_2d(stru->env_copy);
	free(stru->env_copy);
	free(stru->exit_statuses);
	free(stru);
}
