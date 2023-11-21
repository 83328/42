/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 11:17:14 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/20 15:45:45 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int ac, char *av[])
{
	t_data			data;
	t_philo			philos[201];
	pthread_mutex_t	forks[201];

	if (ac < 5 || ac > 6)
	{
		printf("format error\n");
		return (1);
	}
	if (!check_valid_input(av))
	{
		printf("The input must consist of valid positive integers!\n");
		return (2);
	}
	init_data(&data, philos);
	init_forks(forks, ft_atoi(av[1]));
	init_philos(philos, &data, forks, av);
	thread_create(&data, forks);
	destroy_all(&data, forks);
	return (0);
}
