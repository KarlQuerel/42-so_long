/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:16:47 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/17 22:04:57 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks if the player is not trying to move to a wall or an unopened exit */
bool	ft_player_allowed_move(t_data *data, int x, int y)
{
	if (data->map.map[x][y] == 'E' || data->map.map[x][y] == '1')
		return (false);
	return (true);
}

/* Tests one step at a time if all collectibles and the exit are accessible */
// les premieres fois qu'on appelle x et y c'est les coordonnees du player
bool	ft_flood_fill(t_data *data, int x, int y)
{	
	if (data->map.map[x][y] == 'E')
		data->map.exit_status = true;
	if (data->map.exit_status == true && data->count.col
		== data->count.col_back)
		return (true);
	if (ft_player_allowed_move(data, x, y) == true)
	{
		//printf("test0\n");
		if (data->map.map[x][y] == 'C' && data->map.map_dup[x][y] != 'Z')
		{
			data->count.col_back++;
			data->map.map_dup[x][y] = 'Z';
			printf("test1\n");
		}
		if (data->map.map_dup[x][y] == '1' || data->map.map_dup[x][y] == 'Z')
		{
			//printf("test2\n");
			return (false);
		}
		if (data->map.map_dup[x][y] != 'Z')
			data->map.map_dup[x][y] = '1';
		if (ft_flood_fill(data, x, y - 1) == true)
		{
			ft_printf("y - 1 valide\n");
			return (true);
		}
		if (ft_flood_fill(data, x - 1, y) == true)
		{
			ft_printf("x - 1 valide\n");
			return (true);
		}
		if (ft_flood_fill(data, x, y + 1) == true)
		{
			ft_printf("y + 1 valide\n");
			return (true);
		}
		if (ft_flood_fill(data, x + 1, y) == true)
		{
			ft_printf("x + 1 valide\n");
			return (true);
		}
		if (data->map.map_dup[x][y] != 'Z')
			data->map.map_dup[x][y] = '0';
		return (false);
	}
	return (false);
}

/* Creates a duplicate map filled with '0' */
void	ft_init_map_dup(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	data->map.map_dup = malloc(sizeof(char *) * (data->map.map_x));
	while (x < data->map.map_x)
	{
		y = 0;
		while (y < data->map.map_y)
		{
			data->map.map_dup[x] = malloc(sizeof(char) * (data->map.map_y + 1));
			data->map.map_dup[x][y] = '0';
			ft_printf("%c -", data->map.map_dup[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
	data->map.exit_status = false;
	data->count.col_back = 0;
}

/* Prints the duplicate map */
void	ft_print_map_dup(t_data *data)
{
	unsigned int	x;
	unsigned int	y;

	x = 0;
	while (x < data->map.map_x)
	{
		y = 0;
		while (y < data->map.map_y)
		{
			ft_printf("%c ", data->map.map_dup[x][y]);
			y++;
		}
		ft_printf("\n");
		x++;
	}
}
