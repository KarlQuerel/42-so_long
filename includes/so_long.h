/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:09:58 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/23 21:46:01 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#	define SO_LONG_H
#	define right_k 100
#	define right_a 65363
#	define left_k 97
#	define left_a 65361
#	define up_k 119
#	define up_a 65362
#	define down_k 115
#	define down_a 65364
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
	char	*img_path_player_1;
	char	*img_path_player_2;
	char	*img_path_wall;
	char	*img_path_ground;
	char	*img_path_col_1;
	char	*img_path_col_2;
	char	*img_path_exit;
	void	*img_player_1;
	void	*img_player_2;
	void	*img_wall;
	void	*img_ground;
	void	*img_col_1;
	void	*img_col_2;
	void	*img_exit;
	int		img_width;
	int		img_height;
}	t_img;

/* Struct for coordinates */
typedef struct s_coordinates {
	int	x;
	int	y;
}	t_coords;

/* Struc for map */
typedef struct s_map {
	char	**map;
}	t_map;

/* Struct for MLX */
typedef struct	s_data {
	void	*mlx;
	void	*win;
	int		moves;
	int		score;
	t_img	img;
	t_map	map;
	t_coords coords;
}	t_data;


int	ft_check_images(t_data *data);
int	ft_check_map(t_data *data);
int	ft_get_images(t_data *data);
void	ft_put_score(t_data *data);
int	ft_key_press(int keycode, t_data *data);
int	x_click(int keycode);
int	cross_close(t_data *data);
int	ft_put_images_to_map(t_data *data);
void	ft_free(t_data *data);
int	ft_check_mlx(t_data *data);

#	endif
