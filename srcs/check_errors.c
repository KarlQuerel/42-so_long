/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:35:47 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/02 18:01:56 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks MLX init errors */
int	ft_check_images(t_data *data)
{
	if (data->img.player_1 == NULL || data->img.wall == NULL 
	|| data->img.ground == NULL || data->img.col_1 == NULL || data->img.exit_closed == NULL
	|| data->img.exit_open == NULL)
	{
		ft_printf("Error\nImages are not initiated!\n");
		return (1);
	}
	return (0);
}

/* Checks MLX and WIN conditions */
int	ft_check_mlx(t_data *data)
{
	if (!data->mlx)
	{
		ft_printf("Error\nMLX is not initiated!\n");
		return (1);
	}
	if (!data->win)
	{
		ft_printf("Error\nThe window is not initiated!\n");
		return (1);
	}
	return (0);
}