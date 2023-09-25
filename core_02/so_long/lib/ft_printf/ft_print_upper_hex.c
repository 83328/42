/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upper_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:30:51 by alimpens          #+#    #+#             */
/*   Updated: 2023/01/02 19:05:06 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upper_hex(va_list args)
{
	unsigned int	num;
	unsigned int	count;
	char			*my_arr;
	int				i;

	i = 0;
	num = va_arg(args, unsigned int);
	count = ft_count_unsigned_digits(num);
	my_arr = (char *)malloc(sizeof(char) * (count));
	if (!my_arr)
		return (0);
	if (num == 0)
		write(1, "0", 1);
	while (num > 0)
	{
		if (num % 16 >= 10 && num % 16 <= 15)
			my_arr[i++] = 55 + (num % 16);
		else
			my_arr[i++] = 48 + (num % 16);
		num = num / 16;
	}
	while (--i >= 0)
		write (1, &my_arr[i], 1);
	free (my_arr);
	return (count);
}
