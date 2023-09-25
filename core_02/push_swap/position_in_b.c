/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_in_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:29:50 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/25 14:05:16 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

t_node			*node_new_pos_b(t_node *b, t_node *node);
t_node			*min_node_in_stack(t_node *stack);
t_node			*max_node_in_stack(t_node *stack);
static	t_node	*mid_pos_in_stack(t_node *stack, t_node *node);

t_node	*node_new_pos_b(t_node *b, t_node *node)
{
	t_node	*min_node;
	t_node	*max_node;

	if (b == NULL)
		return (b);
	if (b == (b)->next)
		return (b);
	min_node = min_node_in_stack(b);
	max_node = max_node_in_stack(b);
	if (min_node->value > node->value)
		return (max_node);
	if (max_node->value < node->value)
		return (max_node);
	return (mid_pos_in_stack(b, node));
}

t_node	*max_node_in_stack(t_node *stack)
{
	t_node	*max_node;

	if (stack == NULL)
		return (0);
	max_node = stack;
	stack = stack->next;
	while (stack->title != 'h')
	{
		if (max_node->value < stack->value)
			max_node = stack;
		stack = stack->next;
	}
	return (max_node);
}

static t_node	*mid_pos_in_stack(t_node *stack, t_node *node)
{
	while (!(stack->value < node->value
			&& stack->prev->value > node->value))
		stack = stack->next;
	return (stack);
}
