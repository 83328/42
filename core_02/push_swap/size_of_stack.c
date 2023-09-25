/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_of_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:30:05 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/25 16:58:45 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "turk_method.h"

int	size_of_stack(t_node *stack)
{
	int	size;

	if (stack == NULL)
		return (0);
	if (stack == stack->next)
		return (1);
	stack = stack->next;
	size = 1;
	while (stack->title != 'h')
	{
		stack = stack->next;
		++size;
	}
	return (size);
}
