/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:35:04 by dgacic            #+#    #+#             */
/*   Updated: 2023/01/19 10:37:53 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	loop(const char *str, int out, int i);

int	ft_atoi(const char *str)
{
	int	i;
	int	out;
	int	sign;

	i = 0;
	out = 0;
	sign = 1;
	while (str[i])
	{
		if (str[i] < 9 || (str[i] > 13 && str[i] < 32)
			|| (str[i] > 32 && str[i] < 43) || str[i] == 44
			|| (str[i] > 45 && str[i] < 48) || str[i] > 57
			|| ((str[i] == '-' || str[i] == '+') && (str[i + 1] < 48
					|| str[i + 1] > 57)))
			return (0);
		if (str[i] == '-')
			sign = sign * -1;
		if (str[i] >= 48 && str[i] <= 57)
		{
			out = loop(str, out, i) * sign;
			return (out);
		}
		i++;
	}
	return (out);
}

static	int	loop(const char *str, int out, int i)
{
	while (str[i] >= 48 && str[i] <= 57)
	{
		out = out * 10;
		out = out + (str[i] - 48);
		i++;
	}
	return (out);
}
