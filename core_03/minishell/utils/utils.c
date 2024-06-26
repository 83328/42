/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:31:33 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/30 16:26:00 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	perror_exit(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	error_exit(char *msg)
{
	write(2, "%s", ft_strlen(msg));
	exit(EXIT_FAILURE);
}

void	free_loopend(t_struct *stru, int len)
{
	free_2d(stru->input_by_pipes);
	free(stru->input_by_pipes);
	free_2d(stru->reassembled_commands);
	free(stru->reassembled_commands);
	free(stru->pids);
	if (stru->exit_statuses != NULL)
	{
		free(stru->exit_statuses);
		stru->exit_statuses = NULL;
	}
	if (stru->filefds != NULL)
		free(stru->filefds);
	if (stru->pipefds != NULL)
	{
		free_2dint(stru->pipefds, len);
		free(stru->pipefds);
	}
	if (stru->str != NULL)
		free(stru->str);
}

void	init_vars(t_vars *vars)
{
	vars->i = 0;
	vars->j = 0;
	vars->k = 0;
	vars->len = 0;
}

int	check_for_empty_comms(t_struct *stru, char **strings)
{
	int	i;

	i = 0;
	if (strings && strings[i] != NULL && strings[i][0] == '\0')
	{
		if (stru->reassembled_commands != NULL)
		{
			free_2d(stru->reassembled_commands);
			free(stru->reassembled_commands);
		}
		free_mult(stru);
		return (1);
	}
	while (strings[i] != NULL)
	{
		if (strings[i] != NULL && strings[i][0] == '\0')
		{
			write (2, "Empty command before or after pipe operator\n", 45);
			return (1);
		}
		i++;
	}
	return (0);
}
