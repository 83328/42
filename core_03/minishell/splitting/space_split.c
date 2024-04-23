/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:32:43 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/12 13:58:00 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

void	process_string_space_split(char *string, char *reduced_string, \
	int *i, int *j)
{
	int	squoteflag;
	int	dquoteflag;

	squoteflag = -1;
	dquoteflag = -1;
	while (string[*i])
	{
		if (string[*i] == ' ')
		{
			reduced_string[*j] = string[*i];
			(*i)++;
			(*j)++;
		}
		while (string[*i] && string[*i] == ' ' && \
			squoteflag < 0 && dquoteflag < 0)
			(*i)++;
		if (string[*i] && (string[*i] == '\"' || string[*i] == '\''))
			squoteflag = squoteflag * -1;
		if (string[*i] && string[*i] == '\"')
			dquoteflag = dquoteflag * -1;
		if (string[*i])
			reduced_string[(*j)++] = string[(*i)++];
	}
}

char	*space_reduce(char *string)
{
	char	*reduced_string;
	int		i;
	int		j;

	reduced_string = ft_calloc(strlen(string) + 1, sizeof(char));
	i = 0;
	j = 0;
	while (string[i] == ' ')
		i++;
	process_string_space_split(string, reduced_string, &i, &j);
	reduced_string[j] = 0;
	reduced_string = remove_trailing_space(reduced_string);
	return (reduced_string);
}

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
