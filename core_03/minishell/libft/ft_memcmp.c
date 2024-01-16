/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:43:01 by dgacic            #+#    #+#             */
/*   Updated: 2023/01/19 10:43:04 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	size_t				i;
	const unsigned char	*mem1;
	const unsigned char	*mem2;

	mem1 = str1;
	mem2 = str2;
	i = 0;
	while (i < n)
	{
		if (mem1[i] < mem2[i])
		{
			return (mem1[i] - mem2[i]);
		}
		else if (mem1[i] > mem2[i])
		{
			return (mem1[i] - mem2[i]);
		}
		else
			i++;
	}
	return (0);
}
