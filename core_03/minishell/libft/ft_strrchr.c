/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:45:48 by dgacic            #+#    #+#             */
/*   Updated: 2023/01/19 10:45:53 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*right;
	size_t	i;

	right = (char *)s;
	i = ft_strlen(s);
	while (i > 0)
	{
		if (right[i] == (char)c)
			return (right + i);
		i--;
	}
	if (right[i] == (char)c)
		return (right);
	return (0);
}
