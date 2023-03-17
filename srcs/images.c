/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:03:56 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/17 21:45:50 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Gets image from files */
void	ft_get_images(t_data *data)
{	
	data->img.path_player = "textures/player.xpm";
	data->img.player = mlx_xpm_file_to_image(data->mlx, data->img.path_player, &data->img.width, &data->img.height);
	data->img.path_player_2 = "textures/test2.xpm";
	data->img.player_2 = mlx_xpm_file_to_image(data->mlx, data->img.path_player_2, &data->img.width, &data->img.height);
	data->img.path_player_sick = "textures/player_sick.xpm";
	data->img.player_sick = mlx_xpm_file_to_image(data->mlx, data->img.path_player_sick, &data->img.width, &data->img.height);
	data->img.path_wall = "textures/wall.xpm";
	data->img.wall = mlx_xpm_file_to_image(data->mlx, data->img.path_wall, &data->img.width, &data->img.height);
	data->img.path_ground = "textures/grass.xpm";
	data->img.ground = mlx_xpm_file_to_image(data->mlx, data->img.path_ground, &data->img.width, &data->img.height);
	data->img.path_col = "textures/chocolate.xpm";
	data->img.col = mlx_xpm_file_to_image(data->mlx, data->img.path_col, &data->img.width, &data->img.height);
	data->img.path_exit_closed = "textures/exit_closed.xpm";
	data->img.exit_closed = mlx_xpm_file_to_image(data->mlx, data->img.path_exit_closed, &data->img.width, &data->img.height);
	data->img.path_exit_open = "textures/exit_open.xpm";
	data->img.exit_open = mlx_xpm_file_to_image(data->mlx, data->img.path_exit_open, &data->img.width, &data->img.height);
}

/* Checks MLX images */
void	ft_check_images(t_data *data)
{
	if (data->img.player == NULL || data->img.wall == NULL || data->img.player_sick == NULL 
	|| data->img.ground == NULL || data->img.col == NULL || data->img.exit_closed == NULL
	|| data->img.exit_open == NULL)
	{
		ft_printf("Error\nImages are not initiated!\n");
		ft_free(data);
		exit (1);
	}
}

/* Handles image placement given arguments */
void	ft_put_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, data->img.height * y, data->img.width * x);
}

/* Handles animation */
void	ft_player_animation(t_data *data, int x, int y)
{
	if (data->count.counter < 2)
	{		
		ft_put_image(data, data->img.player, x, y);
		//ft_printf("anim1\n");
	}
	else
	{
		ft_put_image(data, data->img.player_2, x, y);
		//ft_printf("anim2\n");
	}
	// else if (data->count.counter < 150)
	// 	ft_put_image(data, data->img.player_1)
	// else if (data->count.counter < 200)
	// 	ft_put_image(data, data->img.player_1)
		
}
