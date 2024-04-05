/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:48:25 by dgacic            #+#    #+#             */
/*   Updated: 2023/01/25 19:48:28 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *str, char c)
{
	int	i;
	int	flip;

	i = 0;
	flip = 0;
	while (*str)
	{
		if (*str != c && flip == 0)
		{
			flip = 1;
			i++;
		}
		else if (*str == c)
			flip = 0;
		str++;
	}
	return (i);
}

static char	*word_copy(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**strarr;

	strarr = (char **) malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !strarr)
		return (NULL);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			strarr[j++] = word_copy(s, index, i);
			index = -1;
		}
		i++;
	}
	strarr[j] = 0;
	return (strarr);
}
