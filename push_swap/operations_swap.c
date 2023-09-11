/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:54:31 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/23 16:26:58 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_node **stack);

void	do_sa(t_node **a)
{
	if (swap(a))
		write(1, "sa\n", 3);
}

void	do_sb(t_node **b)
{
	if (swap(b))
		write(1, "sb\n", 3);
}

void	do_ss(t_node **a, t_node **b)
{
	if (swap(a) + swap(b))
		write(1, "ss\n", 3);
}

static int	swap(t_node **stack)
{
	int	tmp;

	tmp = (*stack)->value;
	if (!(*stack) || (*stack)->next == *stack)
	{
		return (0);
	}
	if ((*stack) && (*stack)->next != *stack)
	{
		(*stack)->value = (*stack)->next->value;
		(*stack)->next->value = tmp;
	}
	return (1);
}
