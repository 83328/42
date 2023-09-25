/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 14:25:02 by alimpens          #+#    #+#             */
/*   Updated: 2023/01/13 16:16:28 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_split(char const *str, char const c);
static char	**hf_ft_split(char const *str, char const c, char **strs, int m);
static int	hf_count_words(char const *str, char const c);
static int	hf_len_word(char const *str, char const c, int i);
static void	hf_free_matrix(char **matrix);

char	**ft_split(char const *str, char const c)
{
	int		m;
	char	**strs;

	m = hf_count_words(str, c);
	strs = (char **)malloc(sizeof(char *) * (m + 1));
	if (!strs)
		return (NULL);
	strs = hf_ft_split(str, c, strs, m);
	if (!str)
		return (NULL);
	return (strs);
}

static char	**hf_ft_split(char const *str, char const c, char **strs, int m)
{
	int		i;
	int		m_;
	int		n;

	i = 0;
	m_ = 0;
	while (m_ < m)
	{
		while (str[i] == c)
			i++;
		n = hf_len_word(str, c, i);
		strs[m_] = ft_substr(str, i, n);
		if (!strs[m_])
		{
			hf_free_matrix(strs);
			return (NULL);
		}
		i += n;
		m_++;
	}
	strs[m_] = NULL;
	return (strs);
}

static int	hf_count_words(char const *str, char const c)
{
	int	n;
	int	found;

	n = 0;
	found = 0;
	while (*str)
	{
		if (*str != c && !found)
		{
			n++;
			found = 1;
		}
		if (*str == c)
			found = 0;
		str++;
	}
	return (n);
}

static int	hf_len_word(char const *str, char const c, int i)
{
	int	n;

	n = 0;
	while (str[i] != c && str[i])
	{
		i++;
		n++;
	}
	return (n);
}

static void	hf_free_matrix(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}
