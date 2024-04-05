/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:44:37 by dgacic            #+#    #+#             */
/*   Updated: 2023/01/19 10:44:38 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (len < size)
	{
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	else if (size)
	{
		ft_memcpy(dst, src, size);
		dst[size - 1] = '\0';
	}
	return (len);
}
