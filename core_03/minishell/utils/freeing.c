/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 14:15:13 by alimpens          #+#    #+#             */
/*   Updated: 2024/04/03 10:54:27 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_2d(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i] != NULL)
		{
			free(array[i]);
			i++;
		}
	}
}

void	free_2dint(int **array, int len)
{
	int	i;

	i = 0;
	if (array)
	{
		while (i < len)
		{
			free(array[i]);
			i++;
		}
	}
}

// void	free_ufds(t_struct *stru)
// {
// 	int	i;
// 	i=0;
// 	while (stru->unused_fds[i] != -1)
// 	{
// 		free(stru->unused_fds[i]);
// 		i++;
// 	}
// 	//free(stru->unused_fds[i]);
// }

// void	free_filefds(t_struct *stru)
// {
// 	int	i;
// 	i=0;
// 	while (stru->filefds[i][0] != -1 ||  stru->filefds[i][1] != -1)
// 	{
// 		if (stru->filefds[i][0] != 0)
// 			free(stru->filefds[i][0]);
// 		if (stru->filefds[i][1] != 0)
// 			free(stru->filefds[i][1]);
// 		i++;
// 	}
// }