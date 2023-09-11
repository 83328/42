/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:30:15 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/23 15:01:46 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_four_nums(t_node **a, t_node **b)
{
	t_node	*min;

	min = min_node_in_stack(*a);
	while (min->title != 'h')
	{
		do_ra(a);
	}
	do_pb(a, b);
	ft_three_nums(a);
	do_pa(a, b);
}
