/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 06:38:01 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/05 06:38:01 by dgacic           ###   ########.fr       */
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
