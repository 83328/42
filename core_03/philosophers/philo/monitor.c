/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:48:04 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/21 12:11:27 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	dead_flag_check(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

int	philo_dead(t_philo *philo, time_t	time_to_die)
{
	pthread_mutex_lock(philo->meal_lock);
	if (get_time() - philo->last_meal >= time_to_die && philo->eating == 0)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

int	check_dead(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos->num_of_philos)
	{
		if (philo_dead(&philos[i], philos[i].time_to_die))
		{
			print_msg("died", &philos[i], philos[i].id);
			pthread_mutex_lock(philos->dead_lock);
			*philos->dead = 1;
			pthread_mutex_unlock(philos->dead_lock);
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_eaten(t_philo *philos)
{
	int	i;
	int	finished_eating;

	i = 0;
	finished_eating = 0;
	if (philos->num_times_to_eat == -1)
		return (0);
	while (i < philos->num_of_philos)
	{
		pthread_mutex_lock(philos->meal_lock);
		if (philos[i].meals_eaten >= philos[i].num_times_to_eat)
			finished_eating++;
		pthread_mutex_unlock(philos->meal_lock);
		i++;
	}
	if (finished_eating == philos->num_of_philos)
	{
		pthread_mutex_lock(philos->dead_lock);
		*philos->dead = 1;
		pthread_mutex_unlock(philos->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *philo)
{
	t_philo	*philos;

	philos = (t_philo *)philo;
	while (1)
	{
		if (check_dead(philos) == 1 || check_eaten(philos) == 1)
			break ;
	}
	return (philo);
}
