/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <dgacic@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:41:13 by dgacic            #+#    #+#             */
/*   Updated: 2023/11/10 02:41:15 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		lenght;
	va_list	args;

	va_start(args, format);
	i = 0;
	lenght = 0;
	while (format[i])
	{
		if (format[i] != '%')
			lenght += write(1, &format[i], 1);
		else
		{
			lenght += checker(format[i + 1], &args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (lenght);
}

int	checker(char c, va_list *args)
{
	int	lenght;

	lenght = 0;
	if (c == 'd' || c == 'i')
		lenght += ft_putnbr_p(va_arg(*args, int));
	if (c == 'c')
		lenght += ft_putchar_p(va_arg(*args, int));
	if (c == 's')
		lenght += ft_putstr_p(va_arg(*args, char *));
	if (c == 'x')
		lenght += ft_hexa_x(va_arg(*args, unsigned int));
	if (c == 'X')
		lenght += ft_hexa_xx(va_arg(*args, unsigned int));
	if (c == 'u')
		lenght += ft_putnbr_un(va_arg(*args, unsigned int));
	if (c == 'p')
		lenght += ft_hexa_adr(va_arg(*args, unsigned long int));
	if (c == '%')
		lenght += write(1, "%", 1);
	return (lenght);
}

int	ft_hexa_x(unsigned int nb)
{
	int	len_x;

	len_x = 0;
	if (nb >= 16)
	{
		len_x += ft_hexa_x(nb / 16);
		nb = nb % 16;
	}
	if (nb < 10)
		len_x += ft_putchar_p(nb + 48);
	if (nb >= 10 && nb < 16)
		len_x += ft_putchar_p(nb + 87);
	return (len_x);
}

int	ft_hexa_xx(unsigned int nb)
{
	int	len_x;

	len_x = 0;
	if (nb >= 16)
	{
		len_x += ft_hexa_xx(nb / 16);
		nb = nb % 16;
	}
	if (nb < 10)
		len_x += ft_putchar_p(nb + 48);
	if (nb >= 10 && nb < 16)
		len_x += ft_putchar_p(nb + 55);
	return (len_x);
}

int	ft_hexa_adr(unsigned long int nb)
{
	int		i;
	int		temp;
	int		lenght;
	char	str[320];

	if (nb == 0)
	{
		lenght = write(1, "(nil)", 5);
		return (lenght);
	}
	i = 0;
	lenght = write(1, "0x", 2);
	while (nb != 0)
	{
		temp = nb % 16;
		if (temp < 10)
			str[i++] = temp + 48;
		if (temp > 9 && temp < 16)
			str[i++] = temp + 87;
		nb /= 16;
	}
	i--;
	while (i >= 0)
		lenght += ft_putchar_p(str[i--]);
	return (lenght);
}
