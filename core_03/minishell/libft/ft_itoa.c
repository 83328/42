/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:29:23 by dgacic            #+#    #+#             */
/*   Updated: 2023/01/25 20:29:26 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_places(int n)
{
	int	count;

	count = 1;
	n = n / 10;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long int	num;
	char		*num_str;
	int			places;

	num = n;
	places = ft_places(n);
	if (n < 0)
	{
		num *= -1;
		places++;
	}
	num_str = (char *)malloc(sizeof(char) * (places + 1));
	if (!num_str)
		return (NULL);
	*(num_str + places) = 0;
	while (places--)
	{
		*(num_str + places) = num % 10 + '0';
		num = num / 10;
	}
	if (n < 0)
		*(num_str + 0) = '-';
	return (num_str);
}
