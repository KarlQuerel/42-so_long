/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:09:58 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/02 19:06:28 by kquerel          ###   ########.fr       */
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
# 	define map_size_x 2000
#	define map_size_y 2000

#include "../minilbx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/X.h>
#include <X11/keysym.h>
#include <X11/cursorfont.h>

/* Struct for images */
typedef struct s_img {
	char	*path_player_1;
	char	*path_player_2;
	char	*path_wall;
	char	*path_ground;
	char	*path_col_1;
	char	*path_col_2;
	char	*path_exit_closed;
	char	*path_exit_open;
	void	*player_1;
	void	*player_2;
	void	*wall;
	void	*ground;
	void	*col_1;
	void	*col_2;
	void	*exit_closed;
	void	*exit_open;
	int		width;
	int		height;
}	t_img;

/* Struct for coordinates */
typedef struct s_coordinates {
	int	x;
	int	y;
	int	x_exit;
	int	y_exit;
}	t_coords;

/* Struc for map */
typedef struct s_map {
	char	**map;
}	t_map;

/* Struct for counts and indexes */
typedef struct s_count {
	int		moves;
	int		score;
	int		player;
	int		exit;
	int		col;
}	t_count;

/* Struct for MLX */
typedef struct	s_data {
	void	*mlx;
	void	*win;
	t_count	count;
	t_img	img;
	t_map	map;
	t_coords coords;
}	t_data;

/* CHECK ERRORS.C */
/* MAPS.C */
/* MOVEMENT.C */
/* CHECK_MAPS.C */
/* IMAGES.C */

int	ft_check_images(t_data *data);
int	ft_check_map_contents(t_data *data);
int	ft_get_images(t_data *data);
void	ft_put_score(t_data *data);
int	ft_key_press(int keycode, t_data *data);
int	x_click(int keycode);
int	cross_close(t_data *data);
int	ft_put_images_to_map(t_data *data);
void	ft_free(t_data *data);
int	ft_check_mlx(t_data *data);
int	ft_check_map_format(t_data *data);
int	ft_check_lines(t_data *data, int n);
int	ft_check_columns(t_data *data, int n);
void	ft_move(t_data *data, int new_x, int new_y);
void	ft_check_col(t_data *data);
void	ft_open_exit(t_data *data);
void	ft_put_image(t_data *data, void *img, int x, int y);

#	endif
