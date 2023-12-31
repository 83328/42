/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_a_to_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:29:56 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/23 16:22:53 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static t_node	*cheapest_node(t_node *stack);
static void		do_rotates_phase_one(t_node **a, t_node **b, t_moves *moves);
static void		do_rotates_phase_two(t_node **a, t_node **b, t_moves *moves);
static t_moves	*cheapest_move(t_node *node);

void	push_from_a_to_b(t_node **a, t_node **b)
{
	t_node	*moving_node;
	t_moves	*move;

	fill_moves_n_steps(*a, *b);
	moving_node = cheapest_node(*a);
	move = cheapest_move(moving_node);
	do_rotates_phase_one(a, b, move);
	do_rotates_phase_two(a, b, move);
	if (*a != moving_node)
		write(1, "ERROR with push_from_a_to_b\n", 28);
	do_pb(a, b);
}

static t_node	*cheapest_node(t_node *stack)
{
	t_node	*cheapest_node;

	if (stack == NULL)
		return (NULL);
	cheapest_node = stack;
	if (stack == stack->next)
		return (cheapest_node);
	stack = stack->next;
	while (stack->title != 'h')
	{
		if (cheapest_node->steps > stack->steps)
			cheapest_node = stack;
		stack = stack->next;
	}
	return (cheapest_node);
}

static void	do_rotates_phase_one(t_node **a, t_node **b, t_moves *moves)
{
	while (moves->rot_a > 0 && moves->rot_b > 0)
	{
		moves->rot_a--;
		moves->rot_b--;
		do_rr(a, b);
	}
	while (moves->rot_a > 0)
	{
		moves->rot_a--;
		do_ra(a);
	}
	while (moves->rot_b > 0)
	{
		moves->rot_b--;
		do_rb(b);
	}
}

static void	do_rotates_phase_two(t_node **a, t_node **b, t_moves *moves)
{
	while (moves->rot_a < 0 && moves->rot_b < 0)
	{
		moves->rot_a++;
		moves->rot_b++;
		do_rrr(a, b);
	}
	while (moves->rot_a < 0)
	{
		moves->rot_a++;
		do_rra(a);
	}
	while (moves->rot_b < 0)
	{
		moves->rot_b++;
		do_rrb(b);
	}
}

static t_moves	*cheapest_move(t_node *node)
{
	t_moves	*move;
	int		i;

	move = &(node->moves[0]);
	i = 1;
	while (i < 4)
	{
		if (move->steps > node->moves[i].steps)
			move = &(node->moves[i]);
		++i;
	}
	return (move);
}
