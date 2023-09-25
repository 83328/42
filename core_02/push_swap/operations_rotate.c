/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:54:31 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/25 16:56:26 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra(t_node **a)
{
	if (rotate(a))
		write (1, "ra\n", 3);
}

void	do_rb(t_node **b)
{
	if (rotate(b))
		write (1, "rb\n", 3);
}

void	do_rr(t_node **a, t_node **b)
{
	if (rotate(a) + rotate(b))
		write (1, "rr\n", 3);
}

int	rotate(t_node **stack)
{
	if (*stack == NULL || *stack == (*stack)->next)
		return (0);
	(*stack)->title = '\0';
	(*stack) = (*stack)->next;
	(*stack)->title = 'h';
	return (1);
}
