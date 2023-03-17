/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:23:34 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/17 21:43:31 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	ft_check_lines(data, 0);
	ft_check_lines(data, data->coords.x - 1);
	ft_check_columns(data, 0);
	ft_check_columns(data, data->coords.y - 1);
	ft_init_map_dup(data);
	if (ft_flood_fill(data, data->coords.x_player, data->coords.y_player) == false)
		{
			ft_printf("Error\nInvalid pathing!\n");
			//ft_free(data);
			//exit(1);
		}
	ft_print_map_dup(data);
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
			ft_free(data);
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
			ft_free(data);
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
			ft_free(data);
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
		ft_printf("Error\nInvalid contents map!\n");
		ft_free(data);
		exit (1);
	}
}