/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_moves_n_steps.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:13:38 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/25 16:55:40 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

static int	max(int x, int y);
static void	fill_moves(t_node *b, t_node *node);
static void	fill_steps(t_node *node);

void	fill_moves_n_steps(t_node *a, t_node *b)
{
	if (a == NULL)
		return ;
	fill_moves(b, a);
	fill_steps(a);
	a = a->next;
	while (a->title != 'h')
	{
		fill_moves(b, a);
		fill_steps(a);
		a = a->next;
	}
}

static void	fill_moves(t_node *b, t_node *node)
{
	node->moves[0].rot_a = dist_w_rot(node);
	node->moves[0].rot_b = dist_w_rot(node_new_pos_b(b, node));
	node->moves[0].steps = max(node->moves[0].rot_a, node->moves[0].rot_b);
	node->moves[1].rot_a = dist_w_rot(node);
	node->moves[1].rot_b = -dist_w_rev_rot(node_new_pos_b(b, node));
	node->moves[1].steps = node->moves[1].rot_a - node->moves[1].rot_b;
	node->moves[2].rot_a = -dist_w_rev_rot(node);
	node->moves[2].rot_b = dist_w_rot(node_new_pos_b(b, node));
	node->moves[2].steps = -node->moves[2].rot_a + node->moves[2].rot_b;
	node->moves[3].rot_a = -dist_w_rev_rot(node);
	node->moves[3].rot_b = -dist_w_rev_rot(node_new_pos_b(b, node));
	node->moves[3].steps = max(-node->moves[3].rot_a, -node->moves[3].rot_b);
}

static void	fill_steps(t_node *node)
{
	int	i;
	int	steps;

	steps = node->moves[0].steps;
	i = 1;
	while (i < 4)
	{
		if (node->moves[i].steps < steps)
			steps = node->moves[i].steps;
		++i;
	}
	node->steps = steps;
}

static int	max(int x, int y)
{
	if (x > y)
		return (x);
	return (y);
}
