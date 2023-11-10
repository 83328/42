/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:31:43 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/10 14:54:58 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_args(int ac, char **av)
{
	int	i;

	if (ac < 5 || 6 < ac)
	{
		printf("Error\n");
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		if (!check_sub1(av, i))
		{
			printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_sub1(char **av, int i)
{
	int	n;

	if (!check_sub2(av[i]))
		return (0);
	n = ft_atoi(av[i]);
	if (i == 1)
		if (!(0 < n && n < 201))
			return (0);
	if (i == 5)
		if (n < 0)
			return (0);
	return (1);
}

int	check_sub2(char *str)
{
	if (!check_digits(str))
		return (0);
	if (!check_int(str))
		return (0);
	return (1);
}

int	check_digits(char *str)
{
	if ((*str == '-' || *str == '+') && ft_strlen(str) > 1)
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	check_int(char *str)
{
	int	n;
	int	n_new;
	int	i;

	i = 0;
	n = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (214748364 < n)
			return (0);
		n *= 10;
		n_new = str[i] - '0';
		if (str[0] != '-')
			if ((2147483647 - n_new) < n)
				return (0);
		if (str[0] == '-')
			if ((-2147483648 + n_new) > -n)
				return (0);
		n += n_new;
		i++;
	}
	return (1);
}
