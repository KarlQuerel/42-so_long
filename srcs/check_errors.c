/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:35:47 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/21 20:28:45 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Checks MLX initiation */
void	ft_check_mlx(t_data *data)
{
	if (!data->mlx)
	{
		ft_printf("Error\nMLX is not initiated!\n");
		ft_remove_normal(data);
		exit (1);
	}
}

/* Checks MLX windows conditions */
void	ft_check_mlx_win(t_data *data)
{
	if (!data->win)
	{
		ft_printf("Error\nThe window is not initiated!\n");
		ft_remove_normal(data);
		exit (1);
	}
}
