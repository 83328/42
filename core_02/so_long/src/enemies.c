/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:58:01 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/24 20:06:20 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	if_touch_enemy(t_game *game, int x, int y)
{
	if (game->map.repo && (game->map.repo[y / IMG_H][x / IMG_W] == \
		CHAR_ENEMY || game->map.repo[y / IMG_H][x / IMG_W] == \
		CHAR_STRONG))
	{
		game->map.repo[y / IMG_H][x / IMG_W] = CHAR_COLLLECT;
		ft_printf("--- OMG! You've touched an enemy.\n");
		mlx_close_window(game->mlx);
	}
}

/* void	enemy_moves(t_game *game, int x, int y)
{
	int	i;
	int	s_x;
	int	s_y;

	i = -1;
	while (++i < game->map.strongs)
	{
		s_x = game->img.strong[i].x;
		s_y = game->img.strong[i].y;
		mlx_delete_image(game->mlx, game->img.strong[i].image);
		game->map.repo[s_y][s_x] = CHAR_FLOOR;
		if (x / IMG_W < s_x && game->map.repo[s_y][s_x - 1] == CHAR_FLOOR)
			s_x--;
		else if (y / IMG_H < s_y && game->map.repo[s_y - 1][s_x] == \
			CHAR_FLOOR)
			s_y--;
		else if (x / IMG_W > s_x && game->map.repo[s_y][s_x + 1] == \
			CHAR_FLOOR)
			s_x++;
		else if (game->map.repo[s_y + 1][s_x] == CHAR_FLOOR)
			s_y++;
		enemy_moves_sub(game, s_x, s_y, i);
	}
}

void	enemy_moves_sub(t_game *game, int strong_x, int strong_y, int i)
{
	game->map.repo[strong_y][strong_x] = CHAR_STRONG;
	place_png_to_img(game, &game->img.strong[i].image, PNG_STRONG_FLIPPED);
	mlx_image_to_window(game->mlx, game->img.strong[i].image, \
		strong_x * IMG_W, strong_y * IMG_H);
	if (game->img.strong[i].x > strong_x)
		game->img.strong[i].x--;
	else if (game->img.strong[i].y > strong_y)
		game->img.strong[i].y--;
	else if (game->img.strong[i].x < strong_x)
		game->img.strong[i].x++;
	else if (game->img.strong[i].y < strong_y)
		game->img.strong[i].y++;
} */
