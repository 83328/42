/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:06:54 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/24 19:56:20 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_player(t_game *game, int x, int y)
{
	place_png_to_img(game, &game->img.player.image, PNG_PLAYER_FRONT0);
	set_player_position(&game->img.player, &game->position);
	mlx_image_to_window(game->mlx, game->img.player.image, \
		x * IMG_W, y * IMG_H);
}

void	init_enemy(t_game *game, int x, int y)
{
	int	i;

	i = game->map.enemies;
	place_png_to_img(game, &game->img.enemy[i].image, PNG_ENEMY);
	game->img.enemy[i].y = y;
	game->img.enemy[i].x = x;
	mlx_image_to_window(game->mlx, game->img.enemy[i].image, \
		x * IMG_W, y * IMG_H);
	game->map.enemies++;
}

void	init_collect(t_game *game, int x, int y, int *count)
{
	place_png_to_img(game, &game->img.collect[*count].image, PNG_COLLECT);
	game->img.collect[*count].x = x;
	game->img.collect[*count].y = y;
	mlx_image_to_window(game->mlx, game->img.collect[*count].image, \
		x * IMG_W, y * IMG_H);
	(*count)++;
}

void	init_exit(t_game *game, int x, int y)
{
	place_png_to_img(game, &game->img.exits[0].image, PNG_EXIT_CLOSE);
	game->img.exits[0].x = x;
	game->img.exits[0].y = y;
	place_png_to_img(game, &game->img.exits[1].image, PNG_EXIT_OPEN);
	game->img.exits[1].x = x;
	game->img.exits[1].y = y;
	mlx_image_to_window(game->mlx, game->img.exits[0].image, \
		x * IMG_W, y * IMG_H);
}

void	random_map_generate(t_game *game, unsigned long int *random_number, \
	int x, int y)
{
	if (*random_number == 0 || *random_number >= 2)
		ft_mlx_image_to_window(game, game->img.floor[0], x, y);
	else if (*random_number == 1)
		ft_mlx_image_to_window(game, game->img.floor[1], x, y);
}
