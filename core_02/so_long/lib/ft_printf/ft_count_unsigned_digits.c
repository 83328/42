/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_unsigned_digits.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:43:08 by alimpens          #+#    #+#             */
/*   Updated: 2023/01/02 19:05:26 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_unsigned_digits(unsigned int numb)
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
			numb = numb / 16;
			i++;
		}
		while (--i >= 0)
			n++;
	}
	return (n);
}
