/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:09:58 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/17 22:21:45 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#	define SO_LONG_H
#	define D_K 100
#	define RIGHT_K 65363
#	define A_K 97
#	define LEFT_K 65361
#	define W_K 119
#	define UP_K 65362
#	define S_K 115
#	define DOWN_K 65364

#include "../minilbx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/cursorfont.h>
#include <stdbool.h>

/* Struct for images */
typedef struct s_img {
	char	*path_player;
	char	*path_player_2;
	char	*path_player_3;
	char	*path_player_4;
	char	*path_player_sick;
	char	*path_wall;
	char	*path_ground;
	char	*path_col;
	char	*path_exit_closed;
	char	*path_exit_open;
	void	*player;
	void	*player_2;
	void	*player_3;
	void	*player_4;
	void	*player_sick;
	void	*wall;
	void	*ground;
	void	*col;
	void	*exit_closed;
	void	*exit_open;
	int		width;
	int		height;
}	t_img;

/* Struct for coordinates */
typedef struct s_coordinates {
	int	x;
	int	y;
	int	cur_x;
	int	cur_y;	
	int	new_x;
	int	new_y;
	int	x_player;
	int	y_player;
	int	x_exit;
	int	y_exit;
}	t_coords;

/* Struc for map */
typedef struct s_map {
	char			**map;
	char			**map_dup;
	unsigned int	map_x;
	unsigned int	map_y;
	bool			exit_status;
}	t_map;

/* Struct for counts and indexes */
typedef struct s_count {
	int		counter;
	int		moves;
	int		score;
	int		player;
	int		exit;
	int		col;
	int		col_back;
}	t_count;

/* Struct for MLX */
typedef struct	s_data {
	void	*mlx;
	void	*win;
	int		x;
	t_count	count;
	t_img	img;
	t_map	map;
	t_coords coords;
}	t_data;


/* MOVEMENT.C */
/* CHECK_MAPS.C */
/* IMAGES.C */

/* SO_LONG.C */
void	ft_read_maps(t_data *data);

/* CHECK ERRORS.C */
void	ft_check_all_mlx(t_data *data);
void	ft_check_mlx(t_data *data);
void	ft_check_mlx_win(t_data *data);

/* CHECK_MAPS.C */
void	ft_check_map_format(t_data *data);
void	ft_check_rectangular(t_data *data);
void	ft_check_columns(t_data *data, int n);
void	ft_check_lines(t_data *data, int n);
void	ft_check_map_contents(t_data *data);

/* EXIT.C */
void	ft_close_game(t_data *data);
void	ft_game_success(t_data *data);
void	ft_free(t_data *data);
int		cross_close(t_data *data);

/* FLOOD_FILL.C */
bool	ft_player_allowed_move(t_data *data, int x, int y);
bool	ft_flood_fill(t_data *data, int x, int y);
void	ft_init_map_dup(t_data *data);
void	ft_print_map_dup(t_data *data);

/* IMAGES.C */
void	ft_get_images(t_data *data);
void	ft_check_images(t_data *data);
void	ft_put_image(t_data *data, void *img, int x, int y);
void	ft_player_animation(t_data *data, int x, int y);

/* TEXT.C */

void	ft_put_score(t_data *data);
int	ft_key_press(int keycode, t_data *data);
int	x_click(int keycode);
int	ft_put_images_to_map(t_data *data);
void	ft_move(t_data *data, int new_x, int new_y);
void	ft_check_col(t_data *data);
void	ft_open_exit(t_data *data);

#	endif
