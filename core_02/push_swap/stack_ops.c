/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:30:01 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/23 19:33:29 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "turk_method.h"

int	size_of_stack(t_node *stack)
{
	int	i;

	if (stack == NULL)
		return (0);
	i = 1;
	stack = stack->next;
	while (stack->title != 'h')
	{
		stack = stack->next;
		++i;
	}
	return (i);
}

int	is_stack_ordered(t_node *a)
{
	t_node	*tmp;

	if (a == 0)
		return (1);
	tmp = a;
	tmp = tmp->prev;
	while (tmp->title != 'h')
	{
		if (tmp->value < tmp->prev->value)
			return (0);
		tmp = tmp->prev;
	}
	return (1);
}

t_node	*create_node(int n)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->value = n;
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->biggest = 0;
	return (new_node);
}

t_node	*create_stack(char **av)
{
	int		i;
	t_node	*new_node;
	t_node	*header;
	t_node	*curr;

	new_node = create_node(ft_atoi(av[1]));
	curr = new_node;
	curr->title = 'h';
	new_node->next = new_node;
	new_node->prev = new_node;
	header = curr;
	i = 2;
	while (av[i])
	{
		new_node = create_node(ft_atoi(av[i]));
		header->prev = new_node;
		new_node->next = header;
		curr->next = new_node;
		new_node->prev = curr;
		curr = new_node;
		curr->title = '\0';
		i++;
	}
	return (header);
}

void	free_stack(t_node *header)
{
	t_node	*curr;
	t_node	*next;

	if (header == NULL)
		return ;
	curr = header->next;
	while (curr != header)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(header);
}
