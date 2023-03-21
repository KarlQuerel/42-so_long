/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:03:56 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/21 20:33:40 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Gets image from files */
void	ft_get_images(t_data *data)
{	
	data->img.path_player = "textures/player.xpm";
	data->img.player = mlx_xpm_file_to_image(data->mlx, data->img.path_player,
			&data->img.width, &data->img.height);
	data->img.path_player_sick = "textures/player_sick.xpm";
	data->img.player_sick = mlx_xpm_file_to_image(data->mlx,
			data->img.path_player_sick, &data->img.width, &data->img.height);
	data->img.path_wall = "textures/wall.xpm";
	data->img.wall = mlx_xpm_file_to_image(data->mlx, data->img.path_wall,
			&data->img.width, &data->img.height);
	data->img.path_ground = "textures/grass.xpm";
	data->img.ground = mlx_xpm_file_to_image(data->mlx, data->img.path_ground,
			&data->img.width, &data->img.height);
	data->img.path_col = "textures/chocolate.xpm";
	data->img.col = mlx_xpm_file_to_image(data->mlx, data->img.path_col,
			&data->img.width, &data->img.height);
	data->img.path_exit_closed = "textures/exit_closed.xpm";
	data->img.exit_closed = mlx_xpm_file_to_image(data->mlx,
			data->img.path_exit_closed, &data->img.width, &data->img.height);
	data->img.path_exit_open = "textures/exit_open.xpm";
	data->img.exit_open = mlx_xpm_file_to_image(data->mlx,
			data->img.path_exit_open, &data->img.width, &data->img.height);
	ft_check_images(data);
}

/* Checks MLX images one by one and calls
ft_remove function to destroy and free appropriately */
void	ft_check_images(t_data *data)
{
	t_items	items;

	items = 42;
	if (data->img.player == NULL)
	{
		ft_printf("Error\nImage_player does not exist!\n");
		ft_remove_images(data, img_player);
	}
	if (data->img.player_sick == NULL)
	{
		ft_printf("Error\nImage_player_sick does not exist!\n");
		ft_remove_images(data, img_player_sick);
	}
	if (data->img.wall == NULL)
	{
		ft_printf("Error\nImage_wall does not exist!\n");
		ft_remove_images(data, img_wall);
	}
	ft_check_images_2(data, items);
}

/* Continuation to ft_check_images */
void	ft_check_images_2(t_data *data, t_items items)
{
	items = 0;
	if (data->img.ground == NULL)
	{
		ft_printf("Error\nImage_ground does not exist!\n");
		ft_remove_images(data, img_ground);
	}
	if (data->img.col == NULL)
	{
		ft_printf("Error\nImage_col does not exist!\n");
		ft_remove_images(data, img_col);
	}
	if (data->img.exit_open == NULL)
	{
		ft_printf("Error\nImage_exit_open does not exist!\n");
		ft_remove_images(data, img_exit_open);
	}
	if (data->img.exit_closed == NULL)
	{
		ft_printf("Error\nImage_exit_closed does not exist!\n");
		ft_remove_images(data, img_exit_closed);
	}
}

/* Handles image placement given arguments */
void	ft_put_image(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img,
		data->img.height * y, data->img.width * x);
}

/* Checks if an image exists, if it does, destroy it in
a safe way to prevent leaks */
void	ft_check_and_destroy(t_data *data, t_items items)
{
	if (items != img_player && data->img.player)
		mlx_destroy_image(data->mlx, data->img.player);
	if (items != img_player_sick && data->img.player_sick)
		mlx_destroy_image(data->mlx, data->img.player_sick);
	if (items != img_wall && data->img.wall)
		mlx_destroy_image(data->mlx, data->img.wall);
	if (items != img_ground && data->img.ground)
		mlx_destroy_image(data->mlx, data->img.ground);
	if (items != img_col && data->img.col)
		mlx_destroy_image(data->mlx, data->img.col);
	if (items != img_exit_open && data->img.exit_open)
		mlx_destroy_image(data->mlx, data->img.exit_open);
	if (items != img_exit_closed && data->img.exit_closed)
		mlx_destroy_image(data->mlx, data->img.exit_closed);
}
