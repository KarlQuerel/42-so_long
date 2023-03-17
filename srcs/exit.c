/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:48:02 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/17 22:09:39 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Manages window termination */
void	ft_close_game(t_data *data)
{
	ft_printf("You quit the game!\n");
	ft_printf("Karl ate %d chocolate(s)!\n", data->count.score);
	ft_printf("There are still %d chocolate(s) running free!\n",
		data->count.col);
	ft_free(data);
	exit(1);
}

/* Ends the game while printing player's final score and moves */
void	ft_game_success(t_data *data)
{
	ft_printf("Good job!\n");
	ft_printf("Karl ate %d chocolates in %d moves!\n", data->count.score,
		data->count.moves);
	ft_free(data);
	exit(1);
}

/* Manages window termination by clicking X */
int	cross_close(t_data *data)
{
	ft_close_game(data);
	return (0);
}

/* Destroys images, windows and displays and frees memory */
//gerer les free avec des enumeration dans la structure
void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx, data->img.player);
	mlx_destroy_image(data->mlx, data->img.player_sick);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.ground);
	mlx_destroy_image(data->mlx, data->img.col);
	mlx_destroy_image(data->mlx, data->img.exit_closed);
	mlx_destroy_image(data->mlx, data->img.exit_open);
	while (data->map.map[i] != NULL)
	{
		free (data->map.map[i]);
		i++;
	}
	free(data->map.map_dup);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	//free(data->win); //double free ici
}
