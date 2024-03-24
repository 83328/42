/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   concat_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:39:02 by alimpens          #+#    #+#             */
/*   Updated: 2024/03/24 19:42:37 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*concat_strings(char** strings, int numStrings)
{
	char* result;

	// Check for valid input
	if (strings[0] == 0 || numStrings <= 0 || strings == NULL) 
	{
		result = ft_calloc(1,sizeof(char));
		return (result);
	}
	// Calculate total length of the concatenated string
	int totalLength = 0;
	int i = 0;

	// Calculate total length using a while loop
	while (i < numStrings) 
		totalLength += strlen(strings[i++]);

	// Add space for the spaces between strings
	totalLength += numStrings - 1;

	if (numStrings < 0)
	{
		return NULL; 
	}

	result = (char*)malloc(totalLength + 1); // +1 for the null terminator
	if (result == NULL)
		return NULL;

	int position = 0;
	i = 0;

	while (i < numStrings)
	{
		strcpy(result + position, strings[i]);
		position += strlen(strings[i]);
		if (i < numStrings - 1) {
			result[position++] = ' '; // Add space between strings
		}
		i++;
	}

	result[totalLength] = '\0'; // Null-terminate the result string
	return result;
}