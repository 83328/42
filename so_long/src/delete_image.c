/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:05:40 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/24 19:57:10 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	delete_item(t_game *game, int x, int y)
{
	int	i;
	int	collect_x;
	int	collect_y;

	collect_x = 0;
	collect_y = 0;
	game->map.repo[y][x] = '0';
	i = -1;
	while (++i < game->map.collects && game->count < game->map.collects)
	{
		if (game->count >= game->map.collects)
			break ;
		collect_x = game->img.collect[i].x;
		collect_y = game->img.collect[i].y;
		if (collect_x == x && collect_y == y)
		{
			mlx_delete_image(game->mlx, game->img.collect[i].image);
			game->count++;
		}
	}
}

void	delete_collectible(t_game *game)
{
	int	finded;
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (++y < game->map.columns)
	{
		x = -1;
		while (++x < game->map.rows)
		{
			if (game->map.repo[y][x] == CHAR_COLLLECT)
				delete_item(game, x, y);
		}
	}
	if (game->count != game->map.collects)
		ft_error_and_free_map("could not delete all floor images", game);
	ft_printf("all collectible items deleted . . .\n");
}

void	delete_player(t_game *game)
{
	int	i;

	i = -1;
	if (!game->img.player.image)
		return ;
	mlx_delete_image(game->mlx, game->img.player.image);
}

void	delete_floor(t_game *game)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		mlx_delete_image(game->mlx, game->img.floor[i]);
		i++;
	}
}

void	delete_all_image(t_game *game)
{
	delete_collectible(game);
	delete_floor(game);
	delete_player(game);
	delete_num(game);
	mlx_delete_image(game->mlx, game->img.exits[0].image);
	mlx_delete_image(game->mlx, game->img.exits[1].image);
	mlx_delete_image(game->mlx, game->img.wall);
}
