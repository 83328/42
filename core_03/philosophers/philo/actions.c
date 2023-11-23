/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:48:46 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/22 11:40:51 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	philo_think(t_philo *philo)
{
	print_msg("is thinking", philo, philo->id);
}

void	philo_sleep(t_philo *philo)
{
	print_msg ("is sleeping", philo, philo->id);
	ft_usleep(philo->time_to_sleep);
}

void	lone_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->r_chopstick);
	ft_usleep(philo->time_to_die);
	pthread_mutex_unlock(philo->r_chopstick);
	return ;
}

int	philo_acquire_chopsticks(t_philo *philo)
{
	pthread_mutex_t	*first_chopstick;
	pthread_mutex_t	*second_chopstick;

	if (philo->r_chopstick < philo->l_chopstick)
	{
		first_chopstick = philo->r_chopstick;
		second_chopstick = philo->l_chopstick;
	}
	else
	{
		first_chopstick = philo->l_chopstick;
		second_chopstick = philo->r_chopstick;
	}
	if (pthread_mutex_lock(first_chopstick) != 0 || \
		(second_chopstick && pthread_mutex_lock(second_chopstick) != 0))
	{
		pthread_mutex_unlock(first_chopstick);
		return (0);
	}
	print_msg("has taken a chopstick", philo, philo->id);
	print_msg("has taken a chopstick", philo, philo->id);
	return (1);
}

void	philo_eat(t_philo *philo)
{
	if (philo->num_of_philos == 1)
		return (lone_philo(philo));
	if (!philo->r_chopstick && !philo->l_chopstick)
	{
		ft_usleep(philo->time_to_eat * 2);
		return ;
	}
	if (philo_acquire_chopsticks(philo) == 0)
	{
		ft_usleep(philo->time_to_eat * 2);
		return ;
	}
	philo->eating = 1;
	print_msg("is eating", philo, philo->id);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_chopstick);
	pthread_mutex_unlock(philo->r_chopstick);
}
