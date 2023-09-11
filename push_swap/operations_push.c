/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 14:54:31 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/25 16:56:32 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_pa(t_node **a, t_node **b)
{
	if (push(a, b))
		write (1, "pa\n", 3);
}

void	do_pb(t_node **a, t_node **b)
{
	if (push(b, a))
		write (1, "pb\n", 3);
}

int	push(t_node **dest, t_node **src)
{
	t_node	*new_head;

	if (*src == NULL)
		return (0);
	if (!(*dest))
	{
		*dest = pull(src);
		(*dest)->next = *dest;
		(*dest)->prev = *dest;
	}
	else if (*dest)
	{
		new_head = pull(src);
		(*dest)->prev->next = new_head;
		new_head->prev = (*dest)->prev; 
		new_head->next = (*dest);
		(*dest)->prev = new_head;
		(*dest)->title = '\0';
		(*dest) = new_head;
	}
	return (1);
}

t_node	*pull(t_node **src)
{
	t_node	*top;

	if (*src == (*src)->next)
	{
		top = *src;
		*src = NULL;
		return (top);
	}
	else
	{
		top = *src;
		(*src)->prev->next = (*src)->next; 
		(*src)->next->prev = (*src)->prev;
		(*src) = (*src)->next;
		(*src)->title = 'h';
	}
	return (top);
}
