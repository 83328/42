/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:50:23 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/04 15:52:54 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_pipes(char *input)
{
	int	num_pipes;
	int	i;

	num_pipes = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '|')
			num_pipes++;
		i++;
	}
	return (num_pipes);
}
