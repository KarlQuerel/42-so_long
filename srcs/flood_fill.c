/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:16:47 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/21 20:21:01 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks if the player is not trying to move to a wall or an unopened exit */
bool	ft_player_allowed_move(t_data *data, int x, int y)
{
	if (data->map.map[x][y] != 'E' && data->map.map[x][y] != '1')
		return (true);
	return (false);
}

/* Starts flood filling at the player position by calling the 
ft_flood_fill_move function. Every time the function finds a 
correct pathing, it writes 1 on the dup map, if it encounters
a collectible, it writes Z. */
bool	ft_flood_fill(t_data *data, int x, int y)
{	
	if (data->map.map[x][y] == 'E')
		data->map.exit_status = true;
	if (data->map.exit_status == true && data->count.col
		== data->count.col_back)
		return (true);
	if (ft_player_allowed_move(data, x, y) == true)
	{
		if (data->map.map_dup[x][y] == '1' || data->map.map_dup[x][y] == 'Z')
			return (false);
		if (data->map.map[x][y] == 'C' && data->map.map_dup[x][y] != 'Z')
		{
			data->count.col_back++;
			data->map.map_dup[x][y] = 'Z';
		}
		if (data->map.map_dup[x][y] != 'Z')
			data->map.map_dup[x][y] = '1';
		if (ft_flood_fill_move(data, x, y) == true)
			return (true);
		return (false);
	}
	return (false);
}

/* Tests one step at a time if all collectibles and the exit are accessible */
bool	ft_flood_fill_move(t_data *data, int x, int y)
{
	if (ft_flood_fill(data, x, y - 1) == true)
		return (true);
	if (ft_flood_fill(data, x - 1, y) == true)
		return (true);
	if (ft_flood_fill(data, x, y + 1) == true)
		return (true);
	if (ft_flood_fill(data, x + 1, y) == true)
		return (true);
	return (false);
}

/* Creates a duplicate map filled with '0' */
void	ft_init_map_dup(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	data->map.map_dup = malloc(sizeof(char *) * (data->map.map_x));
	if (!data->map.map_dup)
		exit (1);
	x = 0;
	while (x < data->map.map_x)
	{
		data->map.map_dup[x] = malloc(sizeof(char) * (data->map.map_y + 1));
		if (!data->map.map_dup[x])
			exit (1);
		y = 0;
		while (y < data->map.map_y)
		{
			data->map.map_dup[x][y] = '0';
			y++;
		}
		data->map.map_dup[x][y] = '\0';
		x++;
	}
	data->map.exit_status = false;
	data->count.col_back = 0;
}
