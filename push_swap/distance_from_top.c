/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   distance_from_top.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:59:59 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/25 16:55:22 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

int	dist_w_rot(t_node *node)
{
	int	dist;

	dist = 0;
	if (node == NULL || node->title == 'h')
		return (dist);
	while (node->title != 'h')
	{
		++dist;
		node = node->prev;
	}
	return (dist);
}

int	dist_w_rev_rot(t_node *node)
{
	int	dist;

	dist = 0;
	if (node == NULL || node->title == 'h')
		return (dist);
	while (node->title != 'h')
	{
		++dist;
		node = node->next;
	}
	return (dist);
}
