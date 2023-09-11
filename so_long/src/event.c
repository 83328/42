/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:05:56 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/24 19:59:15 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	display_move_count(t_game *game)
{
	char	*buffer;
	int		size;

	buffer = NULL;
	delete_num(game);
	size = ft_get_len(game->position.move);
	buffer = ft_itoa(game->position.move);
	if (!buffer)
		ft_error_and_free_map("ah. my life.", game);
	if (ft_get_len(game->position.move) >= game->map.rows)
	{
		delete_all_image(game);
		ft_error_and_free_map("Move count too large to display \
in allocated space", game);
	}
	display_num_to_window(game, buffer, size);
	free(buffer);
	ft_printf("Move:%i\n", game->position.move++);
}

void	count_moves(mlx_key_data_t keydata, int y, int x, t_game *game)
{
	if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) \
		&& keydata.action == MLX_PRESS && \
		game->map.repo[(y - IMG_H) / IMG_H][x / IMG_W] != '1')
		display_move_count(game);
	else if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) \
	&& keydata.action == MLX_PRESS && \
		game->map.repo[(y + IMG_H) / IMG_H][x / IMG_W] != '1')
		display_move_count(game);
	else if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) \
	&& keydata.action == MLX_PRESS && \
		game->map.repo[y / IMG_H][(x - IMG_W) / IMG_W] != '1')
		display_move_count(game);
	else if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) \
	&& keydata.action == MLX_PRESS && \
		game->map.repo[y / IMG_H][(x + IMG_W) / IMG_W] != '1')
		display_move_count(game);
	else if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(game->mlx);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;
	int		*y;
	int		*x;

	game = param;
	y = &game->img.player.image->instances[0].y;
	x = &game->img.player.image->instances[0].x;
	count_moves(keydata, *y, *x, game);
	if (keydata.action == MLX_PRESS)
	{
		if ((keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP) && \
			game->map.repo[(*y - IMG_H) / IMG_H][*x / IMG_W] != '1')
			*y -= IMG_H;
		if ((keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN) && \
			game->map.repo[(*y + IMG_H) / IMG_H][*x / IMG_W] != '1')
			*y += IMG_H;
		if ((keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT) && \
			game->map.repo[*y / IMG_H][(*x - IMG_W) / IMG_H] != '1')
			*x -= IMG_W;
		if ((keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT) && \
			game->map.repo[*y / IMG_H][(*x + IMG_W) / IMG_W] != '1')
			*x += IMG_W;
	}
	collect_item(game, *x, *y);
	if_finish(game, *x, *y);
}

void	collect_item(t_game *game, int x, int y)
{
	int	i;
	int	collect_x;
	int	collect_y;

	collect_x = 0;
	collect_y = 0;
	if (game->map.repo && game->map.repo[y / IMG_H][x / IMG_W] == \
		CHAR_COLLLECT)
	{
		game->map.repo[y / IMG_H][x / IMG_W] = CHAR_FLOOR;
		i = -1;
		while (++i < game->map.collects && game->count < game->map.collects)
		{
			if (game->count >= game->map.collects)
				break ;
			collect_x = game->img.collect[i].x;
			collect_y = game->img.collect[i].y;
			if (collect_x == x / IMG_W && collect_y == y / IMG_H)
			{
				mlx_delete_image(game->mlx, game->img.collect[i].image);
				game->count++;
			}
		}
	}
}

void	if_finish(t_game *game, int x, int y)
{
	if_touch_enemy(game, x, y);
	if (game->count == game->map.collects && game->finish_game != 1)
	{
		ft_printf("Hurray! You've collected everything!\n");
		ft_printf("Now find the *exit* to finish\n");
		mlx_delete_image(game->mlx, game->img.exits[0].image);
		mlx_image_to_window(game->mlx, game->img.exits[1].image, \
			game->img.exits[0].x * IMG_W, \
			game->img.exits[0].y * IMG_H);
		game->finish_game = 1;
	}
	if (game->finish_game == 1 && \
		game->map.repo[y / IMG_H][x / IMG_W] == CHAR_EXIT)
		mlx_close_window(game->mlx);
}
