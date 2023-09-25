/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:07:45 by alimpens          #+#    #+#             */
/*   Updated: 2023/01/02 18:09:01 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_unsigned_digits(unsigned int numb)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	if (numb >= 0 && numb < 10)
		n++;
	else
	{
		while (numb != 0)
		{
			numb = numb / 10;
			i++;
		}
		while (--i >= 0)
			n++;
	}
	return (n);
}

int	ft_print_unsigned(va_list args)
{
	int				i;
	int				count;
	unsigned int	numb;
	char			*my_arr;

	i = 0;
	numb = va_arg(args, unsigned int);
	count = count_unsigned_digits(numb);
	my_arr = (char *)malloc(sizeof(char) * (count));
	if (!my_arr)
		return (0);
	if (numb == 0)
		write(1, "0", 1);
	else
	{
		while (numb != 0)
		{
			my_arr[i++] = (numb % 10) + 48;
			numb = numb / 10;
		}
		while (--i >= 0)
			write (1, &my_arr[i], 1);
	}
	free(my_arr);
	return (count);
}
