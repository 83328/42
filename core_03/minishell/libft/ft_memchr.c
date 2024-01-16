/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:42:47 by dgacic            #+#    #+#             */
/*   Updated: 2023/01/19 10:42:51 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char		uc;
	const unsigned char	*mem;
	size_t				i;

	uc = c;
	i = 0;
	mem = str;
	while (i < n)
	{
		if (mem[i] == uc)
			return ((void *) &mem[i]);
		else
			i++;
	}
	return (NULL);
}
