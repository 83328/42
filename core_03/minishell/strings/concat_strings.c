/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:32:03 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/15 13:50:31 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*calculate_total_length(char **strings, int numstrings)
{
	int	totallength;
	int	i;

	totallength = 0;
	i = 0;
	if (strings[0] == NULL || numstrings <= 0 || strings == NULL)
	{
		return (ft_calloc(1, sizeof(char)));
	}
	while (i < numstrings)
	{
		totallength += ft_strlen(strings[i]);
		i++;
	}
	totallength += numstrings - 1;
	return (ft_itoa(totallength));
}

char	*concat_strings(char **strings, int numstrings)
{
	char	*result;
	int		i;
	int		position;
	char	*total_length_str;

	i = 0;
	position = 0;
	total_length_str = calculate_total_length(strings, numstrings);
	if (total_length_str == NULL || ft_atoi(total_length_str) < 0)
		return (NULL);
	result = ft_calloc(ft_atoi(total_length_str) + 1, sizeof(char));
	free(total_length_str);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < numstrings)
	{
		strcpy(result + position, strings[i]);
		position += ft_strlen(strings[i]);
		if (i < numstrings - 1)
			result[position++] = ' ';
		i++;
	}
	return (result);
}
