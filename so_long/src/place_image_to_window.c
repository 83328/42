/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_image_to_window.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:07:19 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/24 19:51:22 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_floor_with_texture(t_game *game)
{
	int							y;
	int							x;
	static unsigned long int	random_number;

	random_number = 1;
	y = -1;
	while (++y < game->map.columns)
	{
		x = -1;
		while (++x < game->map.rows)
		{
			random_number = ft_rand();
			random_map_generate(game, &random_number, x, y);
		}
	}
}

void	place_layer_with_texture(t_game *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map.columns)
	{
		x = -1;
		while (++x < game->map.rows)
		{
			if (game->map.repo[y][x] == CHAR_WALL)
				mlx_image_to_window(game->mlx, game->img.wall, \
					x * IMG_W, y * IMG_H);
			else if (game->map.repo[y][x] == CHAR_PLAYER)
				init_player(game, x, y);
			else if (game->map.repo[y][x] == CHAR_COLLLECT)
				init_collect(game, x, y, &game->count);
			else if (game->map.repo[y][x] == CHAR_EXIT)
				init_exit(game, x, y);
			else if (game->map.repo[y][x] == CHAR_ENEMY)
				init_enemy(game, x, y);
		}
	}
	ft_mlx_image_to_window(game, game->img.number[0], 1, game->map.columns - 1);
	game->count = 0;
}
