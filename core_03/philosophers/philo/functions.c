/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:32:51 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/21 11:53:10 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_atoi(const char *str)
{
	int			i;
	long int	result;

	i = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (result > 2147483647)
		return (0);
	return (result);
}

int	check_valid_input(char **str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (ft_atoi(str[i]) == 0)
			return (0);
		else if (ft_atoi(str[1]) > 200)
			return (0);
		i++;
	}
	return (1);
}

time_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
	{
		printf("gettimeofday() Failure\n");
		return (1);
	}
	return ((tv.tv_sec * 1000) + tv.tv_usec / 1000);
}

int	ft_usleep(time_t time)
{
	time_t	start;

	start = get_time();
	while ((get_time() - start) < time)
		usleep(time / 10);
	return (0);
}

void	print_msg(char *str, t_philo *philo, int id)
{
	time_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_time() - philo->start_time;
	if (!dead_flag_check(philo))
		printf("%ld %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
