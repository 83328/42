/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:38:54 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/26 16:05:47 by alimpens         ###   ########.fr       */
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
	free(stru->input);
	free_2d(stru->input_by_pipes);
	free_2d(stru->split_by_space);
	free_2d(stru->reassembled_commands);
	free(stru->pids);
	free(stru->filefds);
	//free(stru->pipefds);
	//free_filefds(stru);
	free_2dint(stru->pipefds, len);
}
/*
void	free_child(t_struct *stru)
{
	printf("free_child\n");
}

void	free_exit(t_struct *stru)
{
	printf("free_exit\n");
} */