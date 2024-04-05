/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:43:13 by dgacic            #+#    #+#             */
/*   Updated: 2023/01/19 10:43:16 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*mem1;
	const unsigned char	*mem2;

	mem1 = dest;
	mem2 = src;
	i = 0;
	if (!dest && !src)
		return (0);
	while (i < n)
	{
		mem1[i] = mem2[i];
		i++;
	}
	return (dest);
}
