/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:44:44 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/13 19:43:53 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// verifier longueur et largeur de la map -> que le y de map [0][y] et map [x][y] soit le meme

/* Gets image from files */
void	ft_get_images(t_data *data)
{	
	data->img.path_player_1 = "textures/player.xpm";
	data->img.player_1 = mlx_xpm_file_to_image(data->mlx, data->img.path_player_1, &data->img.width, &data->img.height);
	data->img.path_wall = "textures/wall.xpm";
	data->img.wall = mlx_xpm_file_to_image(data->mlx, data->img.path_wall, &data->img.width, &data->img.height);
	data->img.path_ground = "textures/grass.xpm";
	data->img.ground = mlx_xpm_file_to_image(data->mlx, data->img.path_ground, &data->img.width, &data->img.height);
	data->img.path_col_1 = "textures/chocolate.xpm";
	data->img.col_1 = mlx_xpm_file_to_image(data->mlx, data->img.path_col_1, &data->img.width, &data->img.height);
	data->img.path_exit_closed = "textures/exit_closed.xpm";
	data->img.exit_closed = mlx_xpm_file_to_image(data->mlx, data->img.path_exit_closed, &data->img.width, &data->img.height);
	data->img.path_exit_open = "textures/exit_open.xpm";
	data->img.exit_open = mlx_xpm_file_to_image(data->mlx, data->img.path_exit_open, &data->img.width, &data->img.height);
}

/* Checks if walls are enclosing the map correctly by calling ft_check_lines and ft_check_columns functions */
void	ft_check_map_format(t_data *data)
{
	data->coords.x = 0;
	while (data->map.map[data->coords.x] != NULL)
		data->coords.x++;
	data->coords.y = 0;
	while (data->map.map[0][data->coords.y] != '\0')
		data->coords.y++;
	ft_check_rectangular(data);
	ft_init_map_dup(data);
	ft_get_player_pos(data, data->coords.x_player, data->coords.y_player); //si ca rend false c'est que la map est pas valide
	ft_check_lines(data, 0);
	ft_check_lines(data, data->coords.x - 1);
	ft_check_columns(data, 0);
	ft_check_columns(data, data->coords.y - 1);
}

// /* Checks if the map is rectangular by comparing the first row size to the whole map */
void	ft_check_rectangular(t_data *data)
{
	int	x;
	int	y;
	int	check_y;
	
	x = 0;
	y = 0;
	while (data->map.map[0][y] != '\0')
		y++;
	while (data->map.map[x] != NULL)
	{
		check_y = 0;
		while (data->map.map[x][check_y] != '\0')
			check_y++;
		if(check_y != y)
		{
			ft_printf("Error\nThe map is not rectangular!\n");
			exit (1);
		}
		x++;
	}
	data->map.map_x = x;
	data->map.map_y = y;
}

/* Checks if walls (1) are present on column number n */
void	ft_check_columns(t_data *data, int n)
{	
	data->coords.x = 0;
	while (data->map.map[data->coords.x] != NULL)
	{
		if (data->map.map[data->coords.x][n] != '1')
		{
			ft_printf("Error\nOpen map on line n°%d and column n°%d!\nThe chocolates will escape...\n", data->coords.x, n);
			exit (1);
		}
		data->coords.x++;
	}
}

/* Checks if walls (1) are present on line number n */
void	ft_check_lines(t_data *data, int n)
{
	data->coords.y = 0;
	while (data->map.map[n][data->coords.y] != '\0')
	{
		if (data->map.map[n][data->coords.y] != '1')
		{
			ft_printf("Error\nOpen map on line n°%d and column n°%d!\nThe chocolates will escape...\n", n, data->coords.y);
			exit (1);
		}
		data->coords.y++;
	}
}

/* Checks if map contents (player, collectibles and exit) are valid */
void	ft_check_map_contents(t_data *data)
{
	data->coords.x = 0;
	data->count.player = 0;
	data->count.exit = 0;
	data->count.col = 0;
	while (data->map.map[data->coords.x] != NULL)
	{
		data->coords.y = 0;
		while (data->map.map[data->coords.x][data->coords.y] != '\0')
		{
			if (data->map.map[data->coords.x][data->coords.y] == 'P')
			{
				data->coords.x_player = data->coords.x;
				data->coords.y_player = data->coords.y;
				data->count.player++;
			}
			if (data->map.map[data->coords.x][data->coords.y] == 'E')
				data->count.exit++;
			if (data->map.map[data->coords.x][data->coords.y] == 'C')
				data->count.col++;
			data->coords.y++;
		}
		data->coords.x++;
	}
	if (data->count.player != 1 || data->count.exit != 1 || data->count.col < 1)
	{
		ft_printf("Error\nInvalid map!\n");
		exit (1);
	}
}

/* Handles image placement given arguments */
void	ft_put_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, data->img.height * y, data->img.width * x);
}

/* Places images according to map composition */
int	ft_put_images_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map.map[x])
	{
		y = 0;
		while(data->map.map[x][y] != '\0')
		{
			if (data->map.map[x][y] == '1')
				ft_put_image(data, data->img.wall, x, y);
			else if (data->map.map[x][y] == 'C')
				ft_put_image(data, data->img.col_1, x, y);
			else if (data->map.map[x][y] == '0')
				ft_put_image(data, data->img.ground, x, y);
			else if (data->map.map[x][y] == 'P')
			{
				data->coords.x = x * data->img.height;
				data->coords.y = y * data->img.width;
				ft_put_image(data, data->img.player_1, x, y);
			}
			else if (data->map.map[x][y] == 'E')
			{
				ft_put_image(data, data->img.exit_closed, x, y);
				data->coords.x_exit = x;
				data->coords.y_exit = y;
			}
			y++;
		}
		x++;
	ft_open_exit(data);
	}
	return (0);
}