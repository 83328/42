/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:32:11 by alimpens          #+#    #+#             */
/*   Updated: 2023/01/02 17:47:33 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_print_int(va_list args);
static void	ft_putchar(char c);
static int	ft_print_int_subfunc(int numb, int count);

int	ft_print_int(va_list args)
{
	int		count;
	int		numb;

	numb = va_arg(args, int);
	count = 0;
	if (numb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (numb < 0)
	{
		write(1, "-", 1);
		numb = -numb;
		count++;
	}
	count = ft_print_int_subfunc(numb, count);
	return (count);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static int	ft_print_int_subfunc(int numb, int count)
{
	int		i;
	int		n;
	char	*my_arr;

	n = count_digits(numb);
	my_arr = (char *)malloc(sizeof(char) * n);
	if (!my_arr)
		return (0);
	i = 0;
	if (numb >= 0 && numb < 10)
		ft_putchar((numb + '0'));
	else
	{
		while (numb != 0)
		{
			my_arr[i++] = (numb % 10) + '0';
			numb = numb / 10;
		}
		while (--i >= 0)
			write(1, &my_arr[i], 1);
	}
	free(my_arr);
	return (count + n);
}
