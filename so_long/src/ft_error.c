/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:06:39 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/24 15:02:48 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_general(char *msg)
{
	ft_printf("[ERROR] %s\n", msg);
	exit(1);
}

void	ft_error_and_free_map(char *msg, t_game *game)
{
	ft_printf("[ERROR] %s\n", msg);
	ft_free_map_repo(game->map.repo);
	if (game->map.fill != NULL)
		ft_free_map_fill(game->map.fill, game->map.columns);
	exit(1);
}

void	ft_free_map_fill(char **map, int cols)
{
	int	i;

	if (!map || !*map)
		ft_error_general("Map data not found or invalid.");
	i = 0;
	while (i < cols && map[i] != NULL)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_free_map_repo(char **target)
{
	int	i;

	if (!target || !*target)
		ft_error_general("Map data not found or invalid.");
	i = 0;
	while (target[i] != NULL)
	{
		free(target[i]);
		i++;
	}
	free(target);
}
