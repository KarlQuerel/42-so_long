/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:44:44 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/23 21:50:59 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Gets image from files */
int	ft_get_images(t_data *data)
{	
	data->img.img_path_player_1 = "textures/player.xpm";
	data->img.img_player_1 = mlx_xpm_file_to_image(data->mlx, data->img.img_path_player_1, &data->img.img_width, &data->img.img_height);
	data->img.img_path_wall = "textures/wall.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx, data->img.img_path_wall, &data->img.img_width, &data->img.img_height);
	data->img.img_path_ground = "textures/grass.xpm";
	data->img.img_ground = mlx_xpm_file_to_image(data->mlx, data->img.img_path_ground, &data->img.img_width, &data->img.img_height);
	data->img.img_path_col_1 = "textures/chocolate.xpm";
	data->img.img_col_1 = mlx_xpm_file_to_image(data->mlx, data->img.img_path_col_1, &data->img.img_width, &data->img.img_height);
	data->img.img_path_exit = "textures/exit.xpm";
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx, data->img.img_path_exit, &data->img.img_width, &data->img.img_height);
	return (0);
}

// int	ft_check_map_format(t_data *data)
// {

// }
/* Checks if map is valid */
int	ft_check_map(t_data *data)
{
	int	i;
	int	j;
	int	count_player;
	int	count_exit;
	int	count_col;

	i = 0;
	count_player = 0;
	count_exit = 0;
	count_col = 0;
	while (data->map.map[i] != NULL)
	{
		j = 0;
		while (data->map.map[i][j] != '\0')
		{
			if (data->map.map[i][j] == 'P')
				count_player++;
			if (data->map.map[i][j] == 'E')
				count_exit++;
			if (data->map.map[i][j] == 'C')
				count_col++;
			j++;
		}
		i++;
	}
	if (count_player != 1 && count_exit != 1 && count_col < 1)
	{
		ft_printf("Invalid map!\n");
		return (1);
	}
	return (0);
}

/* Handles image placement given arguments */
void	ft_show_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, data->img.img_height * y, data->img.img_width * x);
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
				ft_show_img(data, data->img.img_wall, x, y);
			else if (data->map.map[x][y] == 'C')
			{
				ft_show_img(data, data->img.img_col_1, x, y);
			}
			else if (data->map.map[x][y] == '0')
				ft_show_img(data, data->img.img_ground, x, y);
			else if (data->map.map[x][y] == 'P')
			{
				data->coords.x = x * data->img.img_height;
				data->coords.y = y * data->img.img_width;
				ft_show_img(data, data->img.img_player_1, x, y);
			}
			else if (data->map.map[x][y] == 'E')
			{
				ft_show_img(data, data->img.img_exit, x, y);
			}
			y++;
		}
		x++;
		ft_put_score(data);
	}
	return (0);
}