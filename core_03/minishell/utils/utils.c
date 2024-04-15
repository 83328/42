/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:31:33 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/12 13:54:40 by alimpens         ###   ########.fr       */
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

int	check_for_empty_comms(char **strings)
{
	int	i;

	i = 0;
	if (strings[i] != NULL && strings[i][0] == '\0')
	{
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
