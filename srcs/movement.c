/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:17:05 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/21 20:51:46 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Calls move function while giving it according arguments to
move the player and handles window closing when pressing ESC */
int	ft_key_press(int keycode, t_data *data)
{
	data->coord.cur_x = data->coord.x / data->img.height;
	data->coord.cur_y = data->coord.y / data->img.width;
	if (keycode == RIGHT_K || keycode == D_K)
		ft_move(data, 0, 1);
	if (keycode == LEFT_K || keycode == A_K)
		ft_move(data, 0, -1);
	if (keycode == UP_K || keycode == W_K)
		ft_move(data, -1, 0);
	if (keycode == DOWN_K || keycode == S_K)
		ft_move(data, 1, 0);
	if (keycode == RIGHT_K || keycode == D_K || keycode == LEFT_K
		|| keycode == A_K || keycode == UP_K || keycode == W_K
		|| keycode == DOWN_K || keycode == S_K)
		ft_put_score(data);
	if (keycode == XK_Escape)
		ft_close_game(data);
	return (0);
}

/* Swaps a "ground" tile and the player position.
New positions are given by the ft_key_press function and checks if
the swap is possible or not */
void	ft_move(t_data *data, int new_x, int new_y)
{
	data->coord.new_x = new_x;
	data->coord.new_y = new_y;
	if (data->map.map[data->coord.cur_x + new_x]
		[data->coord.cur_y + new_y] != '1')
	{
		if (data->map.map[data->coord.cur_x + new_x]
			[data->coord.cur_y + new_y] != 'E')
		{
			if (data->map.map[data->coord.cur_x + new_x]
				[data->coord.cur_y + new_y] == 'C')
			{	
				data->count.score++;
				data->count.col--;
			}
			data->map.map[data->coord.cur_x + new_x]
			[data->coord.cur_y + new_y] = 'P';
			data->map.map[data->coord.cur_x][data->coord.cur_y] = '0';
			data->count.moves++;
			ft_printf("Moves = %d\n", data->count.moves);
		}
		else if (data->map.map[data->coord.cur_x + new_x]
			[data->coord.cur_y + new_y] == 'E' && data->count.col == 0)
			ft_game_success(data);
		ft_put_images_to_map(data);
	}
}

/* If no more collectibles are present on the map, an open exit is
shown on the map and a "sick" player is shown over the normal player*/
void	ft_open_exit(t_data *data)
{
	if (data->count.col == 0)
	{
		ft_put_image(data, data->img.exit_open, data->coord.x_exit,
			data->coord.y_exit);
		ft_put_image(data, data->img.player_sick, data->coord.cur_x
			+ data->coord.new_x, data->coord.cur_y + data->coord.new_y);
	}
}
