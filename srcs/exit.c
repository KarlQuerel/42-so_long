/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 18:48:02 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/21 16:31:50 by kquerel          ###   ########.fr       */
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
	ft_remove_normal(data);
	exit(1);
}

/* Ends the game while printing player's final score and moves */
void	ft_game_success(t_data *data)
{
	ft_printf("Good job!\n");
	ft_printf("Karl ate %d chocolates in %d moves!\n", data->count.score,
		data->count.moves);
	ft_remove_normal(data);
	exit(1);
}

/* Manages window termination by clicking X */
int	cross_close(t_data *data)
{
	ft_close_game(data);
	return (0);
}
