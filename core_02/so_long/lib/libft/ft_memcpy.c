/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:27:13 by alimpens          #+#    #+#             */
/*   Updated: 2022/12/21 16:28:27 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*src_;
	char	*dest_;

	i = 0;
	if (!src && !dest)
		return (NULL);
	src_ = (char *)src;
	dest_ = (char *)dest;
	while (i < n)
	{
		dest_[i] = src_[i];
		i++;
	}
	return (dest);
}
