/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:05:48 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/24 12:01:15 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_number_img(t_game *game, char *str, int i)
{
	if (str[i] == '0')
		place_png_to_img(game, &game->img.number[i], PNG_NUM0);
	if (str[i] == '1')
		place_png_to_img(game, &game->img.number[i], PNG_NUM1);
	if (str[i] == '2')
		place_png_to_img(game, &game->img.number[i], PNG_NUM2);
	if (str[i] == '3')
		place_png_to_img(game, &game->img.number[i], PNG_NUM3);
	if (str[i] == '4')
		place_png_to_img(game, &game->img.number[i], PNG_NUM4);
	if (str[i] == '5')
		place_png_to_img(game, &game->img.number[i], PNG_NUM5);
	if (str[i] == '6')
		place_png_to_img(game, &game->img.number[i], PNG_NUM6);
	if (str[i] == '7')
		place_png_to_img(game, &game->img.number[i], PNG_NUM7);
	if (str[i] == '8')
		place_png_to_img(game, &game->img.number[i], PNG_NUM8);
	if (str[i] == '9')
		place_png_to_img(game, &game->img.number[i], PNG_NUM9);
}

void	display_num_to_window(t_game *game, char *str, int len)
{
	int	start;
	int	i;

	i = -1;
	start = 1;
	while (++i < len)
	{
		set_number_img(game, str, i);
		ft_mlx_image_to_window(game, game->img.number[i], \
			start, game->map.columns - 1);
		start++;
	}
}

void	delete_num(t_game *game)
{
	int		i;
	int		num;
	char	*temp;

	i = 0;
	if (game->position.move == 0)
	{
		mlx_delete_image(game->mlx, game->img.number[0]);
		return ;
	}
	num = game->position.move - 1;
	temp = ft_itoa(num);
	if (!temp)
	{
		delete_all_image(game);
		ft_error_and_free_map("Failed to allocate memory \
while deleting number.", game);
	}
	while (temp[i] != '\0')
	{
		mlx_delete_image(game->mlx, game->img.number[i]);
		i++;
	}
	free(temp);
}
