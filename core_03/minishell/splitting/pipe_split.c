/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:39:35 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/26 14:11:45 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*find_real_pipes(char *input)
{
	int	flag;
	int	i;
	int	*real_pipe_indices;
	int	nth_pipe;
	int	num_pipes;

	i = 0;
	num_pipes = 0;
	if (input[0] == '|')
		perror_exit("Error: pipe at beginning of command");
	while (input[i])
	{
		if (input[i] == '|')
			num_pipes++;
		i++;
	}
	real_pipe_indices = ft_calloc(num_pipes + 1, sizeof(int));
	i = 0;
	nth_pipe = 0;
	while (input[i])
	{
		if (input[i] == '\"' || input[i] == '\'')
		{
			flag = input[i];
			i++;
			while (input[i] != flag)
				i++;
		}
		if (input[i] == '|')
		{
			real_pipe_indices[nth_pipe] = i;
			nth_pipe++;
		}
		i++;
	}
	if (input[i -1] == '|')
		perror_exit("ends on pipe"); 
	real_pipe_indices[nth_pipe] = -1;
	return (real_pipe_indices);
}

char	**pipe_split(char *input)
{
	char	**split_by_pipes;
	int		*real_pipe_indices;
	int		i;

	i = 0;
	real_pipe_indices = find_real_pipes(input);
	split_by_pipes = split_by_index(input, real_pipe_indices);
	return (split_by_pipes);
}
