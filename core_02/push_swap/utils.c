/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:30:34 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/25 16:58:13 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (!(s1[i] == s2[i]))
			return (s1[i] - s2[i]);
		++i;
	}
	if (s1[i])
		return (s1[i]);
	else if (s2[i])
		return (-s2[i]);
	else
		return (0);
}

long long	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13) || str[i] == '0')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}

int	first_confirmed_ordered(t_node *nums)
{
	if (!nums)
		return (0);
	while (nums)
	{
		if (nums->next)
		{
			if (nums->value > nums->next->value)
				return (1);
		}
		nums = nums->next;
	}
	return (0);
}

t_node	*min_node_in_stack(t_node *stack)
{
	t_node	*min_node;

	if (stack == NULL)
		return (0);
	min_node = stack;
	stack = stack->next;
	while (stack->title != 'h')
	{
		if (min_node->value > stack->value)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}
