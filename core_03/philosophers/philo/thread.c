/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 14:28:28 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/22 11:41:17 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	destroy_all(t_data *data, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->meal_check);
	pthread_mutex_destroy(&data->dead_lock);
	while (i < data->philos->num_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	*philo_routine(void	*philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (!dead_flag_check(philo))
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
		ft_usleep(1);
	}
	return (NULL);
}

int	thread_create(t_data *data, pthread_mutex_t	*forks)
{
	pthread_t	checker;
	int			i;

	if (pthread_create(&checker, NULL, &monitor, data->philos) != 0)
		destroy_all(data, forks);
	i = 0;
	while (i < data->philos->num_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine, \
			&data->philos[i]) != 0)
			destroy_all(data, forks);
		i++;
	}
	i = 0;
	if (pthread_join(checker, NULL) != 0)
		destroy_all(data, forks);
	while (i < data->philos->num_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			destroy_all (data, forks);
		i++;
	}
	return (0);
}
