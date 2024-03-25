/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:43:44 by dgacic            #+#    #+#             */
/*   Updated: 2024/03/25 16:40:47 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;

	d = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/* char	*ft_strdup(const char *s)
{
	char	*p;
	int		i;

	i = 0;
	p = (char *) malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	while (*s)
	{
		*p = *s;
		p++;
		s++;
		i++;
	}
	*p = '\0';
	p = p - i;
	return (p);
} */
