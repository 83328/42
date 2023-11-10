/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:53:32 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/10 14:18:43 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <semaphore.h>
#include <unistd.h>

typedef struct s_info
{
	int				print;
	int				death;
	pthread_mutex_t	lock;
}	t_info;

typedef struct s_fork
{
	int				free;
	pthread_mutex_t	lock;
}	t_fork;

typedef struct s_phil
{
	int				n;
	int				id;
	int				first_loop;
	int				n_eat;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				time_rest;
	int				time_start;
	t_fork			*left;
	t_fork			*right;
	t_info			*info;
}	t_phil;

// checkers.c
int		check_args(int ac, char **av);
int		check_sub1(char **av, int i);
int		check_sub2(char *str);
int		check_digits(char *str);
int		check_int(char *str);

// functions.c
int		ft_atoi(const char *str);
int		ft_strlen(const char *str);
int		ft_isdigit(int c);

// 01_info.c
void	make_info(t_info **info);
void	free_info(t_info **info);

// 02_fork.c
void	make_forks(t_fork **forks, int n);
void	free_forks(t_fork **forks, int n);

// philo.c
void	make_phils_sub1(t_phil **phils, int ac, char **av);
void	make_phils_sub2(t_phil **phils, t_info **info, t_fork **forks, int n);
void	free_phils(t_phil **phils);

// 04_thread.c
void	make_threads(pthread_t **threads, int n);
void	start_threads(pthread_t **threads, int n, t_phil **phils);
void	join_threads(pthread_t **threads, int n);
void	free_threads(pthread_t **threads);

// do_die.c
void	do_die(t_phil **phil);
int		is_death(t_phil **phil);

// do_eat.c
int		do_eat(t_phil **phil);
int		get_fork_left(t_phil **phil);
int		get_fork_right(t_phil **phil);
void	let_fork_left(t_phil **phil);
void	let_fork_right(t_phil **phil);

// do_sleep.c
int		do_sleep(t_phil **phil);

// do_think.c
void	do_think(t_phil **phil);

// print.c
void	print(t_phil **phil, char *message);

// routine.c
void	*routine(void *arg);

// time.c
int		get_time_current(void);
int		get_time_elapsed(int time);
int		eat_time(t_phil **phil, int time);

#endif