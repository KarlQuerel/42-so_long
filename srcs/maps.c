/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:44:44 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/17 21:45:54 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Places images according to map composition */
int	ft_put_images_to_map(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	data->count.counter = (data->count.counter + 1) % 4;
	//ft_printf("counter = %d\n", data->count.counter);
	while (data->map.map[x])
	{
		y = 0;
		while (data->map.map[x][y] != '\0')
		{
			if (data->map.map[x][y] == '1')
				ft_put_image(data, data->img.wall, x, y);
			if (data->map.map[x][y] == 'C')
				ft_put_image(data, data->img.col, x, y);
			if (data->map.map[x][y] == '0')
				ft_put_image(data, data->img.ground, x, y);
			if (data->map.map[x][y] == 'P')
			{
				data->coords.x = x * data->img.height;
				data->coords.y = y * data->img.width;
				ft_player_animation(data, x, y);
				//ft_put_image(data, data->img.player, x, y);
			}
			if (data->map.map[x][y] == 'E')
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
