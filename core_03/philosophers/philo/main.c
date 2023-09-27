/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 12:04:44 by alimpens          #+#    #+#             */
/*   Updated: 2023/09/25 15:59:18 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://medium.com/swlh/the-dining-philosophers-problem-bbdb92e6b788

#include "header.h"

int	main(int ac, char **av)
{
	int			n;
	t_info		*info;
	t_fork		*forks;
	t_phil		*phils;
	pthread_t	*threads;

	if(!check_args(ac, av))
		return(0);
	info = NULL;
	forks = NULL;
	phils = NULL;
	threads = NULL;
	n = ft_atoi(av[1]);
	make_info(&info);
	make_forks(&forks, n);
	make_phils_sub1(&phils, ac, av);
	make_phils_sub2(&phils, &info, &forks, n);
	make_threads(&threads, n);
	printf("Syncronization of Threads\n");
	start_threads(&threads, n, &phils);
	join_threads(&threads, n);
	free_forks(&forks, n);
	free_phils(&phils);
	free_threads(&threads);
	free_info(&info);
}