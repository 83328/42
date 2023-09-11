/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:38:46 by alimpens          #+#    #+#             */
/*   Updated: 2023/01/03 21:38:40 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] != '%')
			count = count + write (1, &format[i++], 1);
		if (format[i] == '%' && ft_search_arg(&format[i + 1]))
			count = count + ft_search_arg(&format[i + 1])(args);
		else if (format[i] == '%' && format[i + 1] == '\0')
			break ;
		else if (format[i] == '%' && format[i + 1] != '\0')
			count = count + write(1, &format[i + 1], 1);
		if (format[i] == '%')
			i = i + 2;
	}
	va_end(args);
	return (count);
}

/* #include <unistd.h>
#include <stdio.h>

int main(void)
{
	int count_std = 0;
	int count_hmd = 0;

//	write(1,"STANDARD:\n",10);
//	count_std = printf("My number is %p\n", 123);
	printf("I printed %p characters\n", count_std);

	//write(1,"________________________\n",25);

	//write(1,"HOME_MADE:\n",11);
	//count_hmd = 
	ft_printf("I printed %p characters\n", count_std);
	//printf("I printed %p characters\n", count_hmd);

	return (0);
} */
