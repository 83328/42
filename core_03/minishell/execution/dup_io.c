/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_io.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:34:45 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/08 21:34:45 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../minishell.h"

void	dup_io(int **pipefds, int (*filefds)[2] \
, char **reassembled_commands, int pos)
{
	dup_input(pipefds, filefds, pos);
	dup_output(pipefds, filefds, reassembled_commands, pos);
}

void	dup_input(int **pipefds, int (*filefds)[2], int pos)
{
	if (pos == 0)
	{
		if (filefds[0][0] != 0)
			dup2(filefds[0][0], STDIN);
	}
	else
	{
		if (filefds[pos][0] != 0)
			dup2(filefds[pos][0], STDIN);
		else
			dup2(pipefds[pos -1][0], STDIN);
	}
}

void	dup_output(int **pipefds, int (*filefds)[2] \
, char **reassembled_commands, int pos)
{
	if (reassembled_commands[pos +1] == 0)
	{
		if (filefds[pos][1])
			dup2(filefds[pos][1], STDOUT);
	}
	else
	{
		if (filefds[pos][1])
			dup2(filefds[pos][1], STDOUT);
		else
			dup2(pipefds[pos][1], STDOUT);
	}
}
