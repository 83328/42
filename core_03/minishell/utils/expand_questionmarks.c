/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_questionmarks.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:31:48 by dgacic            #+#    #+#             */
/*   Updated: 2024/04/30 12:31:52 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*malloc_and_check(int len)
{
	char	*new_str;

	new_str = (char *)malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
	{
		fprintf(stderr, "Memory allocation failed.\n");
		exit(EXIT_FAILURE);
	}
	return (new_str);
}

char	*expand_questionmarks(char *str, const char *numerical_string)
{
	size_t	len;
	size_t	j;
	size_t	i;
	char	*new_str;
	size_t	k;

	len = ft_strlen(str);
	new_str = malloc_and_check(len);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (str[i] == '$' && str[i + 1] == '?' && i + 1 < len)
		{
			k = 0;
			while (numerical_string[k] != '\0')
				new_str[j++] = numerical_string[k++];
			i += 2;
		}
		else
			new_str[j++] = str[i++];
	}
	new_str[j] = '\0';
	free(str);
	return (new_str);
}
