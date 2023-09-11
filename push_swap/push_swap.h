/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:31:54 by alimpens          #+#    #+#             */
/*   Updated: 2023/06/23 19:47:30 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_moves
{
	int	rot_a;
	int	rot_b;
	int	steps;
}	t_moves;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
	char			title;
	int				steps;
	char			biggest;
	t_moves			moves[4];
}	t_node;

int			ft_strcmp(char *s1, char *s2);
long long	ft_atoi(char *str);

int			check_duplicates(char **av);
int			check_digit(char *str);
int			check_digits(char **av);

t_node		*create_stack(char **av);
t_node		*create_node(int n);
void		print_stack(t_node *a);
void		free_stack(t_node *header);
t_node		*min_node_in_stack(t_node *stack);
int			is_stack_ordered(t_node *a);
int			check_input(char **av);

void		do_sa(t_node **a);
void		do_sb(t_node **b);
void		do_ss(t_node **a, t_node **b);
void		do_pa(t_node **a, t_node **b);
void		do_pb(t_node **a, t_node **b);
int			push(t_node **a, t_node **b);
int			rotate(t_node **stack);
void		do_rr(t_node **a, t_node **b);
void		do_rb(t_node **b);
void		do_ra(t_node **a);
int			rrotate(t_node **stack);
void		do_rrb(t_node **b);
void		do_rra(t_node **a);
void		do_rrr(t_node **a, t_node **b);
t_node		*pull(t_node **src);

void		ft_two_nums(t_node **stack_a);
void		ft_three_nums(t_node **stack);
void		ft_four_nums(t_node **a, t_node **b);
void		ft_five_nums(t_node **a, t_node **b);

#endif
