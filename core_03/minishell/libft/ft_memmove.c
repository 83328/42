/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:43:23 by dgacic            #+#    #+#             */
/*   Updated: 2023/01/19 10:43:26 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*src_hold;
	char		*dst_hold;

	src_hold = src;
	dst_hold = dest;
	if (!n)
		return (dest);
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	src_hold += n;
	dst_hold += n;
	while (n--)
		*--dst_hold = *--src_hold;
	return ((void *) dest);
}
