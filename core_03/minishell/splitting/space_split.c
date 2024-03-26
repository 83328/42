/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:39:40 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/26 18:41:26 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* void	print_int_array_until_minus_one(int *arr)
{
	printf("[");
	for (int i = 0; arr[i] != -1; i++)
	{
		printf("%d", arr[i]);
		if (arr[i + 1] != -1)
		{
			printf(", ");
		}
	}
	printf("]\n");
} */

char	*remove_trailing_space(char *string)
{
	char	*clipped_string;
	int		i;

	i = 0;
	clipped_string = malloc(ft_strlen(string) + 1 *(sizeof(char)));
	while (string[i])
	{
		clipped_string[i] = string[i];
		i++;
	}
	if (clipped_string[i -1] == ' ')
		clipped_string[i -1] = 0;
	clipped_string[i] = 0;
	free(string);
	return (clipped_string);
}

char	*space_reduce(char *string)
{
	char	*reduced_string;
	int		squoteflag;
	int		dquoteflag;
	int		i;
	int		j;

	reduced_string = ft_calloc(strlen(string) + 1, sizeof(char));
	i = 0;
	j = 0;
	squoteflag = -1;
	dquoteflag = -1;
	while (string[i] == ' ')
		i++;
	while (string[i])
	{
		if (string[i] == ' ')
		{
			reduced_string[j] = string[i];
			i++;
			j++;
		}
		while (string[i] == ' ' && squoteflag < 0 && dquoteflag < 0)
			i++;
		if (string[i] == '\"' || string[i] == '\'')
			squoteflag = squoteflag * -1;
		if (string[i] == '\"')
			dquoteflag = dquoteflag * -1;
		reduced_string[j] = string[i];
		i++;
		j++;
	}
	reduced_string[j] = 0;
	reduced_string = remove_trailing_space(reduced_string);
	return (reduced_string);
}

int	*find_real_spaces(char *reduced_string)
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
}

char	**space_split(char *string)
{
	char	*reduced_string;
	int		*real_space_indices;
	char	**split_by_spaces;

	reduced_string = space_reduce(string);
	real_space_indices = find_real_spaces(reduced_string);
	split_by_spaces = split_by_index(reduced_string, real_space_indices);
	return (split_by_spaces);
}
