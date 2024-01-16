/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgacic <dgacic@student.42berlin.de>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 02:40:45 by dgacic            #+#    #+#             */
/*   Updated: 2023/11/10 02:40:47 by dgacic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar_p(char c)
{
	int	count;

	count = write(1, &c, 1);
	return (count);
}

int	ft_putnbr_p(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		len = write(1, "-2147483648", 11);
		return (len);
	}
	if (nb < 0)
	{
		len += write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		len += ft_putnbr_p(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		len += ft_putchar_p(nb + 48);
	return (len);
}

int	ft_putnbr_un(unsigned int nb)
{
	int	len_un;

	len_un = 0;
	if (nb >= 10)
	{
		len_un += ft_putnbr_un(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		len_un += ft_putchar_p(nb + 48);
	return (len_un);
}

int	ft_putstr_p(char *str)
{
	int	str_len;

	str_len = 0;
	if (!str)
	{
		str_len += write(1, "(null)", 6);
		return (str_len);
	}
	while (*str != '\0')
	{
		str_len += ft_putchar_p(*str);
		str++;
	}
	return (str_len);
}
