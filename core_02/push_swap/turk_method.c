/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_method.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:30:25 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/25 14:14:47 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"
#include "push_swap.h"

void	empty_b(t_node **a, t_node **b);
void	finish_a(t_node **a);

void	turk_method(t_node **a, t_node **b)
{
	if ((size_of_stack(*a)) == 2)
		ft_two_nums(a);
	else if ((size_of_stack(*a)) == 3)
		ft_three_nums(a);
	else if ((size_of_stack(*a)) == 4)
		ft_four_nums(a, b);
	else if ((size_of_stack(*a)) == 5)
		ft_five_nums(a, b);
	else
	{
		while (size_of_stack(*a) > 5 && !is_a_ordered(*a))
		{
			if (is_a_ordered(*a))
				break ;
			push_from_a_to_b(a, b);
		}
		if (size_of_stack(*a) == 5 && !is_a_ordered(*a))
			ft_five_nums(a, b);
		empty_b(a, b);
		finish_a(a);
	}
}

void	empty_b(t_node **a, t_node **b)
{
	t_node	*max_node_b;
	t_node	*new_pos_on_a;

	max_node_b = max_node_in_stack(*b);
	if (dist_w_rot(max_node_b) > dist_w_rev_rot(max_node_b))
		while (max_node_b->title != 'h')
			do_rrb(b);
	else
		while (max_node_b->title != 'h')
			do_rb(b);
	while (*b)
	{
		new_pos_on_a = node_new_pos_a(*a, *b);
		if (dist_w_rot(new_pos_on_a) < dist_w_rev_rot(new_pos_on_a))
			while (new_pos_on_a != *a)
				do_ra(a);
		else
			while (new_pos_on_a != *a)
				do_rra(a);
		do_pa(a, b);
	}
}

void	finish_a(t_node **a)
{
	t_node	*min_node;

	min_node = min_node_in_stack(*a);
	if (dist_w_rot(min_node) > dist_w_rev_rot(min_node))
		while (min_node->title != 'h')
			do_ra(a);
	else
		while (min_node->title != 'h')
			do_rra(a);
}
