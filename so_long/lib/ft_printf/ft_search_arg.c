/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:24:48 by alimpens          #+#    #+#             */
/*   Updated: 2023/01/02 17:46:14 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	(*give_funct(t_func *check_array, const char *format))(va_list args);
int	(*ft_search_arg(const char *format))(va_list args);

int	(*ft_search_arg(const char *format)) (va_list args)
{
	t_func	check_array[10];

	check_array[0].t = "c";
	check_array[0].f = ft_print_char;
	check_array[1].t = "s";
	check_array[1].f = ft_putstr;
	check_array[2].t = "%";
	check_array[2].f = ft_print_perc;
	check_array[3].t = "p";
	check_array[3].f = ft_print_ptr;
	check_array[4].t = "d";
	check_array[4].f = ft_print_int;
	check_array[5].t = "i";
	check_array[5].f = ft_print_int;
	check_array[6].t = "u";
	check_array[6].f = ft_print_unsigned;
	check_array[7].t = "x";
	check_array[7].f = ft_print_hex;
	check_array[8].t = "X";
	check_array[8].f = ft_print_upper_hex;
	check_array[9].t = NULL;
	check_array[9].f = NULL;
	return (give_funct(check_array, format));
}

int	(*give_funct(t_func *check_array, const char *format)) (va_list args)
{
	int	i;

	i = 0;
	while (check_array[i].t != NULL)
	{
		if (*(check_array[i].t) == *format)
			return (check_array[i].f);
		i++;
	}
	return (NULL);
}
