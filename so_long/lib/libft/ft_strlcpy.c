/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:27:30 by alimpens          #+#    #+#             */
/*   Updated: 2022/12/21 16:29:22 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	char			*c;
	unsigned int	i;
	unsigned int	length;

	c = src;
	length = 0;
	while (*c++)
		length++;
	if (size == 0)
		return (length);
	if (length == 0)
	{
		dest[0] = src[0];
		return (length);
	}
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}
