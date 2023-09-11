/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 17:26:26 by alimpens          #+#    #+#             */
/*   Updated: 2022/12/21 17:48:14 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *c)
{
	int					sign;
	unsigned long int	res;
	size_t				i;

	sign = 1;
	i = 0;
	while ((c[i] > 8 && c[i] <= 13) || c[i] == ' ')
		i++;
	if (c[i] == '-')
		sign = sign * -1;
	if (c[i] == '+' || c[i] == '-')
		i++;
	res = 0;
	while (c[i] >= '0' && c[i] <= '9')
	{
		res = res * 10 + (c[i] - '0');
		i++;
	}
	return (res * sign);
}
