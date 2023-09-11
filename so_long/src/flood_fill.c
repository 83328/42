/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:06:08 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/23 14:17:25 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_map_to_fill(t_game *game)
{
	char	**map;
	int		y;
	int		i;

	i = 0;
	if (game->map.fill == NULL)
	{
		y = game->map.columns + 1;
		game->map.fill = (char **)malloc(sizeof(char *) * y);
		if (!game->map.fill)
			ft_error_and_free_map("Failed to allocate memory \
for map fill.", game);
		while (i < game->map.columns)
		{
			game->map.fill[i] = (char *)ft_calloc(game->map.rows + 1, \
			sizeof(char));
			if (!game->map.fill[i])
				ft_error_and_free_map("Failed to allocate memory \
for map fill", game);
			ft_strlcpy(game->map.fill[i], game->map.repo[i], \
			game->map.rows + 1);
			i++;
		}
		game->map.fill[i] = NULL;
	}
}

void	flood_fill(t_game *game, int x, int y, char replacement)
{
	if (x < 0 || x >= game->map.rows || y < 0 || y >= game->map.columns)
		return ;
	game->map.fill[y][x] = replacement;
	if (ft_strchr(IS_FILLED, game->map.fill[y][x - 1]) == NULL)
		flood_fill(game, x - 1, y, replacement);
	if (ft_strchr(IS_FILLED, game->map.fill[y - 1][x]) == NULL)
		flood_fill(game, x, y - 1, replacement);
	if (ft_strchr(IS_FILLED, game->map.fill[y][x + 1]) == NULL)
		flood_fill(game, x + 1, y, replacement);
	if (ft_strchr(IS_FILLED, game->map.fill[y + 1][x]) == NULL)
		flood_fill(game, x, y + 1, replacement);
}

void	find_remain_target(t_game *game, int rows, int cols)
{
	int	y;
	int	x;

	y = 0;
	while (y < cols)
	{
		x = 0;
		while (x < rows)
		{
			if (ft_strchr(CHAR_FILL, game->map.fill[y][x]) != NULL)
				ft_error_and_free_map("hello, stop testing :)", game);
			x++;
		}
		y++;
	}
	ft_free_map_fill(game->map.fill, game->map.columns);
}

void	flood_loop(t_game *game, char **map_fill, char replacement)
{
	int	rows;
	int	cols;

	rows = game->map.rows;
	cols = game->map.columns;
	flood_fill(game, game->position.x, game->position.y, replacement);
	find_remain_target(game, rows, cols);
	ft_printf("Map validated . . .\n");
}
