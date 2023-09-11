/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:27:28 by alimpens          #+#    #+#             */
/*   Updated: 2022/12/21 16:29:17 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size && dst[i])
		i++;
	while (src[j])
	{
		if ((i + j + 1) < size)
		{
			dst[i + j] = src[j];
			k++;
		}
		j++;
	}
	if (i != size)
		dst[i + k] = '\0';
	return (i + j);
}
