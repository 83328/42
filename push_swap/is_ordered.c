/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:16:26 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/25 16:59:39 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

int	is_a_ordered(t_node *a)
{
	if (a == NULL)
		return (true);
	if (a == a->next)
		return (true);
	if (a->value > a->next->value)
		return (false);
	a = a->next;
	while (a->title != 'h')
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

int	is_b_ordered(t_node *b)
{
	if (b == NULL)
		return (true);
	if (b == b->next)
		return (true);
	if (b->value < b->next->value)
		return (false);
	b = b->next;
	while (b->title != 'h')
	{
		if (b->value < b->next->value)
			return (false);
		b = b -> next;
	}
	return (true);
}
