/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_split_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:28:26 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/04 17:29:07 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*space_reduce(char *string)
{
	char	*reduced_string;
	t_state	state;

	reduced_string = ft_calloc(ft_strlen(string) + 1, sizeof(char));
	state.i = 0;
	state.j = 0;
	state.squoteflag = -1;
	state.dquoteflag = -1;
	while (string[state.i] == ' ')
		state.i++;
	while (string[state.i])
	{
		reduced_string = reduce_spaces(string, reduced_string, &state);
		string = toggle_quote_flags(string, &state);
	}
	reduced_string[state.j] = 0;
	reduced_string = remove_trailing_space(reduced_string);
	return (reduced_string);
}

int	count_spaces(char *reduced_string)
{
	int	i;
	int	num_spaces;

	i = 0;
	num_spaces = 0;
	while (reduced_string[i])
	{
		if (reduced_string[i] == ' ')
			num_spaces++;
		i++;
	}
	return (num_spaces);
}

int	*find_space_indices(char *reduced_string, int num_spaces)
{
	int	flag;
	int	i;
	int	nth_space;
	int	*real_space_indices;

	i = 0;
	nth_space = 0;
	real_space_indices = ft_calloc(num_spaces + 1, sizeof(int));
	while (reduced_string[i])
	{
		if (reduced_string[i] == '\"' || reduced_string[i] == '\'')
		{
			flag = reduced_string[i];
			while (reduced_string[++i] != flag)
			{
			}
		}
		if (reduced_string[i] == ' ')
		{
			real_space_indices[nth_space++] = i;
		}
		i++;
	}
	real_space_indices[nth_space] = -1;
	return (real_space_indices);
}

int	*find_real_spaces(char *reduced_string)
{
	int	num_spaces;

	num_spaces = count_spaces(reduced_string);
	return (find_space_indices(reduced_string, num_spaces));
}

/* int	*find_real_spaces(char *reduced_string)
{
	int	flag;
	int	i;
	int	*real_space_indices;
	int	nth_space;
	int	num_spaces;

	i = 0;
	num_spaces = 0;
	while (reduced_string[i])
	{
		if (reduced_string[i] == ' ')
			num_spaces++;
		i++;
	}
	real_space_indices = ft_calloc(num_spaces + 1, sizeof(int));
	i = 0;
	nth_space = 0;
	while (reduced_string[i])
	{
		if (reduced_string[i] == '\"' || reduced_string[i] == '\'')
		{
			flag = reduced_string[i];
			i++;
			while (reduced_string[i] != flag)
				i++;
		}
		if (reduced_string[i] == ' ')
		{
			real_space_indices[nth_space] = i;
			nth_space++;
		}
		i++;
	}
	real_space_indices[nth_space] = -1;
	return (real_space_indices);
} */

char	**space_split(char *string)
{
	char	*reduced_string;
	int		*real_space_indices;
	char	**split_by_spaces;

	reduced_string = space_reduce(string);
	real_space_indices = find_real_spaces(reduced_string);
	split_by_spaces = split_by_index(reduced_string, real_space_indices);
	free(reduced_string);
	free(real_space_indices);
	return (split_by_spaces);
}
