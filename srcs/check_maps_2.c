/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_maps_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 20:08:30 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/21 20:49:05 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks if maps are with the correct format .ber by calling 
ft_is_map_ber. Then proceeds to open the map and calls 
all checking functions */
void	ft_check_map_name(t_data *data)
{
	if (ft_is_map_ber(data->arguments, ".ber") == false)
	{
		ft_printf("Error\nInvalid map name!\n");
		exit (1);
	}
	ft_read_maps(data);
	ft_check_map_format(data);
	ft_map_status(data);
	ft_check_flood_fill(data);
}

/* Checks if the last 4 chars of the map name is ".ber" */
bool	ft_is_map_ber(char *str, char *to_compare)
{
	size_t	i;
	size_t	j;

	i = ft_strlen_gnl(str) - 4;
	j = 0;
	while (str[i] || to_compare[j])
	{
		if (str[i] != to_compare[j])
			return (false);
		i++;
		j++;
	}
	return (true);
}

/* Checks if map contents are valid */
void	ft_map_status(t_data *data)
{
	data->coord.x = 0;
	data->count.player = 0;
	data->count.exit = 0;
	data->count.col = 0;
	if (ft_check_map_contents(data) == false)
	{
		ft_printf("Error\nInvalid contents map!\n");
		ft_free_map(data);
		exit (1);
	}
}

/* Checks if pathing is valid */
void	ft_check_flood_fill(t_data *data)
{
	ft_init_map_dup(data);
	if (ft_flood_fill(data, data->coord.x_player,
			data->coord.y_player) == false)
	{
		ft_printf("Error\nInvalid pathing!\n");
		ft_free_map_both(data);
		exit(1);
	}
}
