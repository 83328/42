/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rrotate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:54:31 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/25 16:56:21 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rra(t_node **a)
{
	if (rrotate(a))
		write (1, "rra\n", 4);
}

void	do_rrb(t_node **b)
{
	if (rrotate(b))
		write (1, "rrb\n", 4);
}

void	do_rrr(t_node **a, t_node **b)
{
	if (rrotate(a) + rrotate(b))
		write (1, "rrr\n", 4);
}

int	rrotate(t_node **stack)
{
	if (*stack == NULL || *stack == (*stack)->next)
		return (0);
	(*stack)->title = '\0';
	(*stack) = (*stack)->prev;
	(*stack)->title = 'h';
	return (1);
}
