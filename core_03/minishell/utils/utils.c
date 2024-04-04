/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:54 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/03 11:28:46 by alimpens         ###   ########.fr       */
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
	dprintf(2, "%s", msg);
	exit(EXIT_FAILURE);
}

void	free_loopend(t_struct *stru, int len)
{
	free_2d(stru->input_by_pipes);
	free(stru->input_by_pipes);
	free_2d(stru->reassembled_commands);
	free(stru->reassembled_commands);
	free(stru->pids);
	free(stru->filefds);
	free_2dint(stru->pipefds, len);
	free(stru->pipefds);
	stru->pipefds = NULL;
}
