/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alimpens <alimpens@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 14:52:29 by alimpens          #+#    #+#             */
/*   Updated: 2023/08/24 19:55:43 by alimpens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* header*/
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

/* mlx library */
# include "MLX42.h"

/* library */
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>

/* define */
# define MAP_WIDTH	2880
# define MAP_HEIGHT	2880

# define IMG_W		64
# define IMG_H		64

# define NUM_FRAMES	4
# define RAND_FLOWERS	20

/* char */
# define CHAR_MAP			"01PECM"
# define CHAR_FILL			"CEPM"
# define IS_FILLED			"1X"
# define CHAR_WALL			49
# define CHAR_EXIT			69
# define CHAR_PLAYER		80
# define CHAR_COLLLECT		67
# define CHAR_FLOOR			48
# define CHAR_ENEMY			77
# define CHAR_STRONG		83

/* player path */
# define PNG_PLAYER_FRONT0	"./assets/char_front/character.png"
# define PNG_PLAYER_FRONT1	"./assets/char_front/character.png"
# define PNG_PLAYER_FRONT3	"./assets/char_front/character.png"
# define PNG_PLAYER_FRONT2	"./assets/char_front/character.png"

/* enemies path */
# define PNG_ENEMY			"./assets/enemies/enemy_yellow.png"
# define PNG_ENEMY_FLIPPED	"./assets/enemies/enemy_blue.png"
# define PNG_STRONG			"./assets/enemies/enemy_yellow.png"
# define PNG_STRONG_FLIPPED	"./assets/enemies/enemy_blue.png"

/* collect path */
# define PNG_COLLECT		"./assets/collect/chest.png"

# define PNG_EXIT_OPEN		"./assets/exit/exit_open.png"
# define PNG_EXIT_CLOSE		"./assets/exit/exit_close.png"

/* wall path */
# define PNG_WALL			"./assets/walls/water.png"

/* floor path */
# define PNG_FLOOR0			"./assets/floor/frame1/grass_00.png"
# define PNG_FLOOR1			"./assets/floor/frame1/grass_01.png"

/* number path */
# define PNG_NUM0			"./assets/numbers/num_0.png"
# define PNG_NUM1			"./assets/numbers/num_1.png"
# define PNG_NUM2			"./assets/numbers/num_2.png"
# define PNG_NUM3			"./assets/numbers/num_3.png"
# define PNG_NUM4			"./assets/numbers/num_4.png"
# define PNG_NUM5			"./assets/numbers/num_5.png"
# define PNG_NUM6			"./assets/numbers/num_6.png"
# define PNG_NUM7			"./assets/numbers/num_7.png"
# define PNG_NUM8			"./assets/numbers/num_8.png"
# define PNG_NUM9			"./assets/numbers/num_9.png"

/* struct */
typedef struct s_multi{
	mlx_image_t	*image;
	int			x;
	int			y;
}				t_multi;

typedef struct s_img{
	mlx_image_t	*floor[2];
	t_multi		exits[2];
	t_multi		player;
	t_multi		enemy[100];
	t_multi		collect[1000];
	mlx_image_t	*wall;
	mlx_image_t	*number[10];
}				t_img;

typedef struct s_map{
	char	**repo;
	char	**fill;
	int		columns;
	int		rows;
	int		collects;
	int		player;
	int		enemies;
	int		strongs;
	int		exits;
	int		walls;
	int		floor;
}				t_map;

typedef struct s_position{
	int					x;
	int					y;
	unsigned int		move;
	char				*num_display;
}				t_position;

/* game */
typedef struct s_game{	
	mlx_t		*mlx;
	int			fd;
	t_img		img;
	t_map		map;
	t_position	position;
	int			count;
	int			finish_game;
}				t_game;

/* prototype & main */
void	place_texture(t_game *game);
void	clean_up(t_game *game);

/* error */
void	ft_error_general(char *msg);
void	ft_error_and_free_map(char *msg, t_game *game);
void	ft_free_map_repo(char **target);
void	ft_free_map_fill(char **map, int cols);

/* utility */
int		ft_rand(void);
int		ft_readline(char *str);
void	ft_mlx_image_to_window(t_game *game, mlx_image_t *mlx_image, \
	int x, int y);
void	place_png_to_img(t_game *game, mlx_image_t **img, char *path);
int		ft_get_len(long nb);

/* valid map */
void	check_surround_wall(int x, int y, t_game *game);
void	check_argument(int ac, char **av, t_game *game);
void	check_possibility_clear_game(t_game *game);
void	collect_map_struct(char c, t_game *game, int x, int y);
void	valid_map(t_game *game);

/* init game */
void	init_value(t_game *game);
void	set_player_position(t_multi *info, t_position *position);
void	set_enemy_position(t_multi *info, t_position *position);
void	init_mlx(t_game *game);

/* init map */
void	map_2d_malloc(t_game *game);
void	check_map_len(t_game *game, char *line, int index);
void	init_map(char **av, t_game *game);

/* init image */
void	init_floors(t_game *game);
void	init_player(t_game *game, int x, int y);
void	init_enemy(t_game *game, int x, int y);
void	init_collect(t_game *game, int x, int y, int *count);
void	init_exit(t_game *game, int x, int y);
void	random_map_generate(t_game *game, unsigned long int *random_number, \
	int x, int y);

/* place image to window */
void	place_floor_with_texture(t_game *game);
void	place_layer_with_texture(t_game *game);

/* event */
void	count_moves(mlx_key_data_t keydata, int y, int x, t_game *game);
void	key_hook(mlx_key_data_t keydata, void *param);
void	collect_item(t_game *game, int x, int y);
void	if_finish(t_game *game, int x, int y);

/* enemies event */
void	if_touch_enemy(t_game *game, int x, int y);
void	write_counter(t_game *game);
void	write_level(t_game *game);
void	enemy_watch_player(t_game *game, int x, int y);
void	enemy_moves(t_game *game, int x, int y);
void	enemy_moves_sub(t_game *game, int strong_x, int strong_y, int i);
void	animate(void *param);
int		animate_enemies(t_game *game, int i, int flag, char *image);

/* delete image */
void	delete_item(t_game *game, int x, int y);
void	delete_collectible(t_game *game);
void	delete_player(t_game *game);
void	delete_floor(t_game *game);
void	delete_all_image(t_game *game);

/* display move */
void	display_num_to_window(t_game *game, char *str, int len);
void	delete_num(t_game *game);

/* flood fill */
void	copy_map_to_fill(t_game *game);
void	flood_loop(t_game *game, char **map_fill, char replacement);
void	flood_fill(t_game *game, int x, int y, char replacement);
#endif
