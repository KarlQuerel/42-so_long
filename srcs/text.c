/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:59:06 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/21 18:46:46 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Displays score, moves and fixed text on the window */
void	ft_put_score(t_data *data)
{
	char	*move_or_score;
	char	*final_text;

	move_or_score = ft_itoa(data->count.moves);
	final_text = ft_strjoin("MOVES = ", move_or_score);
	mlx_set_font(data->mlx, data->win, "10x20");
	mlx_string_put(data->mlx, data->win, 2, 40, 0x00BFFF, final_text);
	free (move_or_score);
	free (final_text);
	move_or_score = ft_itoa(data->count.score);
	final_text = ft_strjoin("CHOCOLATES = ", move_or_score);
	mlx_string_put(data->mlx, data->win, 82, 60, 0x5FFB17, final_text);
	mlx_string_put(data->mlx, data->win, 40, 20, 0xFFFFFF, "S O    L O N G");
	mlx_string_put(data->mlx, data->win, 22, data->map.map_x * 80 - 52,
		0xDAEE01, "KARL IS HUNGRY...");
	mlx_string_put(data->mlx, data->win, 102, data->map.map_x * 80 - 32,
		0x5FFB17, "F E E D");
	mlx_string_put(data->mlx, data->win, 132, data->map.map_x * 80 - 12,
		0x5FFB17, "H I M !");
	free(move_or_score);
	free(final_text);
	ft_check_col(data);
}

/* If no more collectibles are present on the map, rewrites a string
with the same color as the brick (wall) to erase the previous message
and shows a new message on the map */
void	ft_check_col(t_data *data)
{
	if (data->count.col == 0)
	{
		mlx_set_font(data->mlx, data->win, "10x20");
		mlx_string_put(data->mlx, data->win, 22, data->map.map_x * 80 - 52,
			0x800000, "KARL IS HUNGRY...");
		mlx_string_put(data->mlx, data->win, 102, data->map.map_x * 80 - 32,
			0x800000, "F E E D");
		mlx_string_put(data->mlx, data->win, 132, data->map.map_x * 80 - 12,
			0x800000, "H I M !");
		mlx_string_put(data->mlx, data->win, 22, data->map.map_x * 80 - 52,
			0x7FE817, "KARL IS NOW SICK...");
		mlx_string_put(data->mlx, data->win, 52, data->map.map_x * 80 - 32,
			0xFFA500, "TAKE HIM TO");
		mlx_string_put(data->mlx, data->win, 82, data->map.map_x * 80 - 12,
			0xFFA500, "THE HOSPITAL!");
	}
}
