/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:17:05 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/09 18:48:34 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* If no more collectibles are present on the map, rewrites a string with the same color 
as the brick (wall) to erase the previous message and shows a new message on the map */
void ft_check_col(t_data *data)
{
    if (data->count.col == 0)
    {
        mlx_set_font(data->mlx, data->win, "10x20");
        mlx_string_put(data->mlx, data->win, map_size_x / 7, 40, 0x800000, "KARL IS HUNGRY...");
		mlx_string_put(data->mlx, data->win, map_size_x / 5, 60, 0x800000, "FEED HIM!");
	    mlx_string_put(data->mlx, data->win, map_size_x / 7, 40, 0x7FE817, "KARL IS NOW SICK...");
	    mlx_string_put(data->mlx, data->win, map_size_x / 5, 60, 0xFFA500, "TAKE HIM TO THE HOSPITAL!");
    }
}

/* If no more collectibles are present on the map, an open exit is shown on the map */
void    ft_open_exit(t_data *data)
{
    if (data->count.col == 0)
        ft_put_image(data, data->img.exit_open, data->coords.x_exit, data->coords.y_exit);
}

/* Ends the game while printing player's final score and moves */
void    ft_game_success(t_data *data)
{
    ft_printf("Good job!\n");
    ft_printf("You made Karl eat %d chocolates in %d moves!\n", data->count.score, data->count.moves);
    ft_free(data);
    exit(1);
}