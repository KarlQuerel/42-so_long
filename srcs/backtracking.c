/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:16:47 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/13 19:50:07 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool    ft_get_player_pos(t_data *data, int x, int y)
{
	//le premier grand if est si on est arrive a la fin (P est sur E ET que data count col = 0)
	//on sort de la fonction, return true
	
	//ft_printf("--%c--\n", data->map.map[x][y - 2]); // comment ca se fait que je peux print un truc en dehors de la map??
	//creer fonction pour voir si le player n'essaie pas de se deplacer sur un 1 ou E
	//qui sera mon 2eme if
	//if (bidule)
	{
		//if si ton nouveau x et y veulent deplacer le player sur une case deja visitee de ta map dup, si oui tu return false
		//data->map.map_dup[x][y] = '1' --> on ecrit 1 sur map dup

		if (ft_get_player_pos(data, x, y - 1) == TRUE)
			return (TRUE);
		if (ft_get_player_pos(data, x - 1, y) == TRUE)
			return (TRUE);
		if (ft_get_player_pos(data, x, y + 1) == TRUE)
			return (TRUE);
		if (ft_get_player_pos(data, x + 1, y) == TRUE)
			return (TRUE);
		data->map.map_dup[x][y] = '0';
		return (FALSE);
	}
	return (FALSE);
}

/* Creates a dup map filled with '0' */
void   ft_init_map_dup(t_data *data)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	data->map.map_dup = malloc(sizeof(char *) * (data->map.map_x));
	while (x < data->map.map_x)
	{
		y = 0;
		while (y < data->map.map_y)
		{
			data->map.map_dup[x] = malloc(sizeof(char) * (data->map.map_y + 1));
			data->map.map_dup[x][y] = '0';
			//ft_printf("%c, ", data->map.map_dup[x][y]);
			y++;
		}
		//ft_printf("\n");
		x++;
	}
}

void   ft_print_map_dup(t_data *data)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	data->map.map_dup = malloc(sizeof(char *) * (data->map.map_x));
	while (x < data->map.map_x)
	{
		y = 0;
		while (y < data->map.map_y)
		{
			data->map.map_dup[x] = malloc(sizeof(char) * (data->map.map_y + 1));
			data->map.map_dup[x][y] = '0';
			//ft_printf("%c, ", data->map.map_dup[x][y]);
			y++;
		}
		//ft_printf("\n");
		x++;
	}
}