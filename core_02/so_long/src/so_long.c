/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:07:32 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/25 11:35:37 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_texture(t_game *game)
{
	place_floor_with_texture(game);
	place_layer_with_texture(game);
	ft_printf("*** Get ready to play! ***\n");
}

void	clean_up(t_game *game)
{
	delete_all_image(game);
	ft_free_map_repo(game->map.repo);
	mlx_terminate(game->mlx);
	ft_printf("*** cleaning up all data... ***\n");
}

int	main(int ac, char **av)
{
	t_game	game;

	check_argument(ac, av, &game);
	init_value(&game);
	game.fd = open(av[1], O_RDONLY);
	if (game.fd < 0 || game.fd == 0)
		ft_error_general("Failed to open file. [fd]");
	init_map(av, &game);
	valid_map(&game);
	init_mlx(&game);
	init_floors(&game);
	place_texture(&game);
	mlx_loop_hook(game.mlx, &animate, &game.mlx);
	mlx_key_hook(game.mlx, &key_hook, &game.mlx);
	mlx_loop(game.mlx);
	clean_up(&game);
}

void	animate(void *param)
{
	t_game		*game;
	static int	count;
	static int	i;
	static int	flag;

	game = param;
	count++;
	if (game->map.enemies == 0)
		return ;
	if (count >= 1)
	{
		if (flag == 0)
			flag = animate_enemies(game, i, flag, PNG_STRONG_FLIPPED);
		else if (flag == 1)
			flag = animate_enemies(game, i, flag, PNG_STRONG);
		i++;
		if (i == game->map.enemies)
			i = 0;
		count = 0;
	}
}

int	animate_enemies(t_game *game, int i, int flag, char *path)
{
	int	enemy_x;
	int	enemy_y;

	enemy_x = game->img.enemy[i].x;
	enemy_y = game->img.enemy[i].y;
	mlx_delete_image(game->mlx, game->img.enemy[i].image);
	place_png_to_img(game, &game->img.enemy[i].image, path);
	mlx_image_to_window(game->mlx, game->img.enemy[i].image, \
		enemy_x * IMG_W, enemy_y * IMG_H);
	i++;
	if (i == game->map.enemies && flag == 0)
		return (1);
	if ((i == game->map.enemies && flag == 1) || flag == 0)
		return (0);
	return (1);
}
