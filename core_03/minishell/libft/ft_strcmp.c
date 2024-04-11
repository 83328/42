/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 19:03:16 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/10 14:50:05 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;
	size_t	n;
	int		len1;
	int		len2;

	if (s1 == NULL || s2 == NULL)
		return (1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		n = len1;
	else
		n = len2;
	i = 0;
	while (i < n)
	{
		if (s1[i] == 0 && s2[i] == 0)
			return (0);
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
