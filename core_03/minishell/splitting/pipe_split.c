/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:32:43 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/15 13:50:13 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	process_input(char *input, int *real_pipe_indices, int *nth_pipe)
{
	int		i;
	char	flag;

	i = 0;
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
			real_pipe_indices[*nth_pipe] = i;
			(*nth_pipe)++;
		}
		i++;
	}
}

int	*find_real_pipes(char *input)
{
	int	i;
	int	*real_pipe_indices;
	int	nth_pipe;
	int	num_pipes;

	i = 0;
	num_pipes = 0;
	if (input[0] == '|')
	{
		fprintf(stderr, "Error: pipe at beginning of command");
		_exit(EXIT_FAILURE);
	}
	while (input[i])
	{
		if (input[i] == '|')
			num_pipes++;
		i++;
	}
	real_pipe_indices = ft_calloc(num_pipes + 1, sizeof(int));
	nth_pipe = 0;
	process_input(input, real_pipe_indices, &nth_pipe);
	if (input[i -1] == '|')
		perror_exit("ends on pipe");
	real_pipe_indices[nth_pipe] = -1;
	return (real_pipe_indices);
}

char	**pipe_split(char *input)
{
	char	**split_by_pipes;
	int		*real_pipe_indices;

	real_pipe_indices = find_real_pipes(input);
	split_by_pipes = split_by_index(input, real_pipe_indices);
	free(real_pipe_indices);
	return (split_by_pipes);
}
