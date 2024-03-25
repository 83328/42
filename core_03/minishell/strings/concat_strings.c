/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:39:02 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/25 18:06:57 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*concat_strings(char** strings, int numStrings)
{
	char* result;
	if (strings[0] == 0 || numStrings <= 0 || strings == NULL) 
	{
		result = ft_calloc(1,sizeof(char));
		return (result);
	}
	int totalLength = 0;
	int i = 0;
	while (i < numStrings) 
		totalLength += ft_strlen(strings[i++]);
	totalLength += numStrings - 1;
	if (numStrings < 0)
	{
		return NULL; 
	}
	result = (char*)malloc(totalLength + 1);
	if (result == NULL)
		return NULL;
	int position = 0;
	i = 0;

	while (i < numStrings)
	{
		strcpy(result + position, strings[i]);
		position += ft_strlen(strings[i]);
		if (i < numStrings - 1)
		{
			result[position++] = ' ';
		}
		i++;
	}
	result[totalLength] = '\0';
	return result;
}
