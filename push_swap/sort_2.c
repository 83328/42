/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:30:08 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/23 15:40:27 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "turk_method.h"

void	ft_two_nums(t_node **stack_a)
{
	t_node	*tmp;

	tmp = *stack_a;
	if (tmp->value > tmp->next->value)
		do_sa(stack_a);
	*stack_a = tmp;
}
