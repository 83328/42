/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:53:54 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/24 19:44:23 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_floors(t_game *game)
{
	place_png_to_img(game, &game->img.floor[0], PNG_FLOOR0);
	place_png_to_img(game, &game->img.floor[1], PNG_FLOOR1);
	place_png_to_img(game, &game->img.wall, PNG_WALL);
	place_png_to_img(game, &game->img.number[0], PNG_NUM0);
}
