/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:35:47 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/23 21:45:17 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks MLX init errors */
int	ft_check_images(t_data *data)
{
	if (data->img.img_player_1 == NULL || data->img.img_wall == NULL 
	|| data->img.img_ground == NULL || data->img.img_col_1 == NULL || data->img.img_exit == NULL)
	{
		ft_printf("Error while initiating images!\n");
		return (1);
	}
	return (0);
}

int	ft_check_mlx(t_data *data)
{
	if (!data->mlx)
	{
		ft_printf("Error while initiating MLX\n");
		return (1);
	}
	if (!data->win)
	{
		ft_printf("Error while initiating the window\n");
		return (1);
	}
	return (0);
}