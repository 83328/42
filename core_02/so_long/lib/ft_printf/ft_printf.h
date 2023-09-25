/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 14:06:44 by alimpens          #+#    #+#             */
/*   Updated: 2023/01/02 20:10:37 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct func
{
	char	*t;
	int		(*f)(va_list);
}	t_func;

int	ft_printf(const char *format, ...);
int	(*ft_search_arg(const char *format))(va_list args);
int	ft_print_char(va_list args);
int	ft_putstr(va_list args);
int	count_digits(int numb);
int	ft_print_perc(va_list args);
int	ft_print_ptr(va_list args);
int	ft_print_int(va_list args);
int	ft_print_unsigned(va_list args);
int	ft_print_hex(va_list args);
int	ft_print_upper_hex(va_list args);
int	ft_count_unsigned_digits(unsigned int numb);

#endif
