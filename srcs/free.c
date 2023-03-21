/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:15:25 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/21 20:33:55 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Handles all free exit possibilites and leakages
in case of images errors. */
void	ft_remove_images(t_data *data, t_items items)
{
	ft_check_and_destroy(data, items);
	ft_free_map_both(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (1);
}

/* Handles all free exit possibilites 
and leakages when no problems are encoutered */
void	ft_remove_normal(t_data *data)
{
	ft_destroy(data);
	ft_free_map_both(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit (1);
}

/* Frees both maps line by line */
void	ft_free_map_both(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i] != NULL)
	{
		free (data->map.map[i]);
		free (data->map.map_dup[i]);
		i++;
	}
	free (data->map.map_dup);
	free (data->map.map);
}

/* Frees map.map line by line */
void	ft_free_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i] != NULL)
	{
		free (data->map.map[i]);
		i++;
	}
	free (data->map.map);
}

/* Destroy all images */
void	ft_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.player);
	mlx_destroy_image(data->mlx, data->img.player_sick);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.ground);
	mlx_destroy_image(data->mlx, data->img.col);
	mlx_destroy_image(data->mlx, data->img.exit_open);
	mlx_destroy_image(data->mlx, data->img.exit_closed);
}
