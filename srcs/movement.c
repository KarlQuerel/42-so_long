/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:17:05 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/02 19:08:35 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* If no more collectibles are present on the map, shows a new message on the map */
void ft_check_col(t_data *data)
{
    if (data->count.col == 0)
    {
        mlx_set_font(data->mlx, data->win, "10x20");
	    mlx_string_put(data->mlx, data->win, map_size_x / 7, 40, 0x7FE817, "KARL IS NOW SICK...");
	    mlx_set_font(data->mlx, data->win, "10x20");
	    mlx_string_put(data->mlx, data->win, map_size_x / 5, 60, 0xFFA500, "TAKE HIM TO THE HOSPITAL!");
    }
}

/* If no more collectibles are present on the map, a new exit shows on the map */
void    ft_open_exit(t_data *data)
{
    if (data->count.col == 0)
    {
        ft_put_image(data, data->img.exit_open, data->coords.x_exit, data->coords.y_exit);
    }
}