/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:30:11 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/23 15:31:04 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_three_nums(t_node **stack)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*stack)->value;
	middle = (*stack)->next->value;
	bottom = (*stack)->next->next->value;
	if (middle < bottom && middle < top && bottom > top)
		do_sa(stack);
	if (top > middle && top > bottom && middle > bottom)
	{
		do_sa(stack);
		do_rra(stack);
	}
	if (top > middle && top > bottom && middle < bottom)
		do_ra(stack);
	if (top < middle && top > bottom && middle > bottom)
		do_rra(stack);
	if (top < middle && top < bottom && middle > bottom)
	{
		do_sa(stack);
		do_ra(stack);
	}
}
