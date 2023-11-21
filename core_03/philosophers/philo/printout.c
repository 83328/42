/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 17:00:52 by alimpens          #+#    #+#             */
/*   Updated: 2023/11/17 13:35:20 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	printout(t_info **info)
{
	*info = (t_info *)malloc(sizeof(t_info));
	if (!(*info))
		return ;
	(*info)->print = 1;
	(*info)->death = 0;
	pthread_mutex_init(&((*info)->lock), NULL);
}

void	free_printout(t_info **info)
{
	free(*info);
}
