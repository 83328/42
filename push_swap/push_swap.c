/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:30:01 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/23 19:50:21 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "turk_method.h"

int	main(int ac, char **av)
{
	int		i;
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (0);
	if (check_input(av) == 0)
		return (0);
	if (ac == 2)
		return (0);
	a = create_stack(av);
	if (is_stack_ordered(a) == 1)
	{
		free_stack(a);
		return (0);
	}
	turk_method(&a, &b);
	free_stack(a);
	return (0);
}

int	check_input(char **av)
{
	int		i;

	if (check_digits(av) == 0)
		return (0);
	i = 0;
	while (av[++i])
		if (check_duplicates(&av[i]) == 1)
			return (0);
	i = 1;
	while (av[i])
	{
		if (INT_MIN > (long long)ft_atoi(av[i]) 
			|| INT_MAX < (long long)ft_atoi(av[i]))
			return (0 & write(1, "Error\n", 6));
		i++;
	}
	return (1);
}
