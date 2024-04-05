/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:37:25 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 06:37:25 by dgacic           ###   ########.fr       */
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
	free(stru->str);
	stru->pipefds = NULL;
}

void	init_vars(t_vars *vars)
{
	vars->i = 0;
	vars->j = 0;
	vars->k = 0;
	vars->len = 0;
}
