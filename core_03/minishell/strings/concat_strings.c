/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:39:02 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/26 18:47:35 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*concat_strings(char **strings, int numstrings)
{
	char	*result;
	int		totallength;
	int		i;
	int		position;

	totallength = 0;
	i = 0;
	position = 0;
	if (strings[0] == 0 || numstrings <= 0 || strings == NULL) 
	{
		result = ft_calloc(1, sizeof(char));
		return (result);
	}
	while (i < numstrings) 
		totallength += ft_strlen(strings[i++]);
	totallength += numstrings - 1;
	if (numstrings < 0)
	{
		return (NULL); 
	}
	result = (char *)malloc(totallength + 1);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (i < numstrings)
	{
		strcpy(result + position, strings[i]);
		position += ft_strlen(strings[i]);
		if (i < numstrings - 1)
		{
			result[position++] = ' ';
		}
		i++;
	}
	result[totallength] = '\0';
	return (result);
}
