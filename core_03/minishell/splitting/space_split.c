/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:39:40 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/04 17:30:05 by alimpens         ###   ########.fr       */
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

/* char	*space_reduce(char *string)
{
	char	*reduced_string;
	int		squoteflag;
	int		dquoteflag;
	int		i;
	int		j;

	reduced_string = ft_calloc(ft_strlen(string) + 1, sizeof(char));
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
} */

char	*reduce_spaces(char *string, char *reduced_string, t_state *state)
{
	while (string[state->i] == ' ')
		(state->i)++;
	while (string[state->i])
	{
		if (string[state->i] == ' ')
		{
			reduced_string[state->j] = string[state->i];
			(state->i)++;
			(state->j)++;
		}
		while (string[state->i] == ' ' 
			&& state->squoteflag < 0 && state->dquoteflag < 0)
			(state->i)++;
		reduced_string[state->j] = string[state->i];
		(state->i)++;
		(state->j)++;
	}
	reduced_string[state->j] = 0;
	return (reduced_string);
}

char	*toggle_quote_flags(char *string, t_state *state)
{
	if (string[state->i] == '\"' || string[state->i] == '\'')
		state->squoteflag = state->squoteflag * -1;
	if (string[state->i] == '\"')
		state->dquoteflag = state->dquoteflag * -1;
	return (string);
}
