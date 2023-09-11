/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 11:07:45 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/24 19:49:31 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_rand(void)
{
	static unsigned long int	random_number;
	char						*base;
	unsigned long int			seed;

	base = malloc(1);
	if (!base)
		ft_error_general("Failed to generate random number\n");
	seed = (unsigned long int)base;
	free(base);
	random_number = random_number * seed * 1103515245 + 12345;
	return ((unsigned int)(random_number / 65536) % RAND_FLOWERS);
}

int	ft_readline(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			str[i] = '\0';
		i++;
	}
	return (i);
}

void	ft_mlx_image_to_window(t_game *game, mlx_image_t *mlx_image, \
			int x, int y)
{
	mlx_image_to_window(game->mlx, mlx_image, x * IMG_W, y * IMG_H);
	if (!mlx_image)
	{
		ft_free_map_repo(game->map.repo);
		ft_error_general("mlx image uninit");
	}
}

void	place_png_to_img(t_game *game, mlx_image_t **img, char *path)
{
	mlx_texture_t	*my_texture;

	my_texture = mlx_load_png(path);
	if (!my_texture)
		ft_error_and_free_map("wow! texture messed up.", game);
	*img = mlx_texture_to_image(game->mlx, my_texture);
	mlx_delete_texture(my_texture);
	if (!*img)
		ft_error_and_free_map("wow! image messed up.", game);
}

int	ft_get_len(long nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
