/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 13:40:50 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/05 14:09:49 by alimpens         ###   ########.fr       */
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
			free(s->input_by_pipes[i]);
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
	free(s->filefds);
	free(s->pids);
	free(s->line);
	free(s->exit_statuses);
	free(s->str);
}

void	free_exit(t_struct *s)
{
	if (s != NULL)
	{
		free_env_copy(s);
		free_split_by_space(s);
		free_reassembled_commands(s);
		free_input_by_pipes(s);
		free_pipefds(s);
		free_single_pointers(s);
		free(s);
	}
}
