/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 21:23:34 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/21 20:49:19 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks if map contents (player, collectibles and exit) are valid */
//TOO MANY LINES
bool	ft_check_map_contents(t_data *data)
{
	while (data->map.map[data->coord.x] != NULL)
	{
		data->coord.y = 0;
		while (data->map.map[data->coord.x][data->coord.y] != '\0')
		{
			if (data->map.map[data->coord.x][data->coord.y] == 'P')
			{
				data->coord.x_player = data->coord.x;
				data->coord.y_player = data->coord.y;
				data->count.player++;
			}
			else if (data->map.map[data->coord.x][data->coord.y] == 'E')
				data->count.exit++;
			else if (data->map.map[data->coord.x][data->coord.y] == 'C')
				data->count.col++;
			else if (data->map.map[data->coord.x][data->coord.y] != '0'
				&& data->map.map[data->coord.x][data->coord.y] != '1')
				return (false);
			data->coord.y++;
		}
		data->coord.x++;
	}
	if (data->count.player != 1 || data->count.exit != 1 || data->count.col < 1)
		return (false);
	return (true);
}

/* Checks if walls are enclosing the map correctly by calling
ft_check_lines and ft_check_columns functions */
void	ft_check_map_format(t_data *data)
{
	data->coord.x = 0;
	while (data->map.map[data->coord.x] != NULL)
		data->coord.x++;
	data->coord.y = 0;
	while (data->map.map[0][data->coord.y] != '\0')
		data->coord.y++;
	ft_check_rectangular(data);
	ft_check_lines(data, 0);
	ft_check_lines(data, data->coord.x - 1);
	ft_check_columns(data, 0);
	ft_check_columns(data, data->coord.y - 1);
}

/* Checks if the map is rectangular by comparing the first row
size to the whole map */
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
		if (check_y != y)
		{
			ft_printf("Error\nThe map is not rectangular!\n");
			ft_free_map(data);
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
	data->coord.x = 0;
	while (data->map.map[data->coord.x] != NULL)
	{
		if (data->map.map[data->coord.x][n] != '1')
		{
			ft_printf("Error\n");
			ft_printf("Open map on line n°%d and column n°%d!\n",
				data->coord.x, n);
			ft_printf("The chocolates will escape...\n");
			ft_free_map(data);
			exit (1);
		}
		data->coord.x++;
	}
}

/* Checks if walls (1) are present on line number n */
void	ft_check_lines(t_data *data, int n)
{
	data->coord.y = 0;
	while (data->map.map[n][data->coord.y] != '\0')
	{
		if (data->map.map[n][data->coord.y] != '1')
		{
			ft_printf("Error\n");
			ft_printf("Open map on line n°%d and column n°%d!\n",
				data->coord.y, n);
			ft_printf("The chocolates will escape...\n");
			ft_free_map(data);
			exit (1);
		}
		data->coord.y++;
	}
}
