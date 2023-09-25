/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:07:42 by alimpens          #+#    #+#             */
/*   Updated: 2023/01/02 18:10:16 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(int numb)
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
