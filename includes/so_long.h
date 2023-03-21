/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 21:09:58 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/21 21:02:19 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define D_K 100
# define RIGHT_K 65363
# define A_K 97
# define LEFT_K 65361
# define W_K 119
# define UP_K 65362
# define S_K 115
# define DOWN_K 65364

# include "../minilbx/mlx.h"
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <X11/cursorfont.h>
# include <stdbool.h>

/* Struct for freeing imaes */
typedef enum e_items {
	img_player,
	img_player_sick,
	img_wall,
	img_ground,
	img_col,
	img_exit_open,
	img_exit_closed,
}	t_items;

/* Struct for images */
typedef struct s_img {
	char	*path_player;
	char	*path_player_sick;
	char	*path_wall;
	char	*path_ground;
	char	*path_col;
	char	*path_exit_closed;
	char	*path_exit_open;
	void	*player;
	void	*player_sick;
	void	*wall;
	void	*ground;
	void	*col;
	void	*exit_open;
	void	*exit_closed;
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
}	t_coord;

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
	int		moves;
	int		score;
	int		player;
	int		exit;
	int		col;
	int		col_back;
}	t_count;

/* Struct for MLX */
typedef struct s_data {
	void	*mlx;
	void	*win;
	int		x;
	char	*arguments;
	t_coord	coord;
	t_count	count;
	t_img	img;
	t_map	map;
}	t_data;

/* CHECK ERRORS.C */
void	ft_check_mlx(t_data *data);
void	ft_check_mlx_win(t_data *data);

/* CHECK_MAPS_2.C */
void	ft_check_map_name(t_data *data);
void	ft_map_status(t_data *data);
void	ft_check_flood_fill(t_data *data);
bool	ft_is_map_ber(char *str, char *to_compare);

/* CHECK_MAPS.C */
void	ft_check_map_format(t_data *data);
void	ft_check_rectangular(t_data *data);
void	ft_check_columns(t_data *data, int n);
void	ft_check_lines(t_data *data, int n);
bool	ft_check_map_contents(t_data *data);

/* EXIT.C */
void	ft_close_game(t_data *data);
void	ft_game_success(t_data *data);
int		cross_close(t_data *data);

/* FLOOD_FILL.C */
bool	ft_player_allowed_move(t_data *data, int x, int y);
bool	ft_flood_fill(t_data *data, int x, int y);
bool	ft_flood_fill_move(t_data *data, int x, int y);
void	ft_init_map_dup(t_data *data);

/* FREE.C */
void	ft_remove_images(t_data *data, t_items items);
void	ft_remove_normal(t_data *data);
void	ft_free_map_both(t_data *data);
void	ft_free_map(t_data *data);
void	ft_destroy(t_data *data);

/* IMAGES.C */
void	ft_get_images(t_data *data);
void	ft_check_images(t_data *data);
void	ft_check_images_2(t_data *data, t_items items);
void	ft_put_image(t_data *data, void *img, int x, int y);
void	ft_check_and_destroy(t_data *data, t_items items);

/* MAPS.C */
void	ft_read_maps(t_data *data);
void	ft_put_images_player(t_data *data, int x, int y);
void	ft_put_images_exit(t_data *data, int x, int y);
int		ft_put_images_to_map(t_data *data);

/* MOVEMENT.C */
int		ft_key_press(int keycode, t_data *data);
void	ft_move(t_data *data, int new_x, int new_y);
void	ft_open_exit(t_data *data);

/* TEXT.C */
void	ft_put_score(t_data *data);
void	ft_check_col(t_data *data);

#	endif
