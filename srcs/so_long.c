/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:56:10 by kquerel           #+#    #+#             */
/*   Updated: 2023/02/23 21:57:05 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// regarder strerror et perror et exit
// backtracking ?
//etape 50 check map si elle est bien fermee, si il y a un seul P, si il y a au moins un C et un E

#include "../includes/so_long.h"

/* Displays score, moves and fixed text on the window */
void	ft_put_score(t_data *data)
{
	char	*move;
	char	*move_final;
	//char	*score;
	//char	*score_final;

	move = ft_itoa(data->moves);
	move_final = ft_strjoin("MOVES = ", move);
	mlx_set_font(data->mlx, data->win, "10x20");
	mlx_string_put(data->mlx, data->win, 80, 40, 0x00BFFF, move_final);
	move = ft_itoa(data->moves);
	move_final = ft_strjoin("CHOCOLATES = ", move);
	mlx_set_font(data->mlx, data->win, "10x20");
	mlx_string_put(data->mlx, data->win, 80, 60, 0x5FFB17, move_final);
	mlx_set_font(data->mlx, data->win, "10x20");
	mlx_string_put(data->mlx, data->win, map_size_x / 7, 40, 0xDAEE01, "KARL IS HUNGRY...");
	mlx_set_font(data->mlx, data->win, "10x20");
	mlx_string_put(data->mlx, data->win, map_size_x / 5, 60, 0x5FFB17, "FEED HIM!");
	free (move);
	free (move_final);
}

//NEEDS to swap les valeurs entre P et le reste dans data->map.map puis faire appel a ft_image_map
/* Manages keys pressed - player movements and esc exit */
// int	ft_key(int keycode, t_data *data)
// {
// 	static int pos_x = 0;
// 	static int pos_y = 0;
// 	int	new_pos;
// 	if (keycode == right_k || keycode == right_a)
// 	{
// 		new_pos = pos_x + data->img.img_width;
// 		while (pos_x <= new_pos)
// 		{
// 			mlx_put_image_to_window(data->mlx, data->win, data->img.img_player_1, pos_x, pos_y);
// 			pos_x++;
// 		}
// 	}
// 	else if (keycode == left_k || keycode == left_a)
// 	{
// 		new_pos = pos_x - data->img.img_width;
// 		while (pos_x >= new_pos)
// 		{
// 			mlx_put_image_to_window(data->mlx, data->win, data->img.img_player_1, pos_x, pos_y);
// 			pos_x--;
// 		}
// 	}
// 	else if (keycode == down_k || keycode == down_a)
// 	{
// 		new_pos = pos_y + data->img.img_height;
// 		while (pos_y <= new_pos)
// 		{
// 			mlx_put_image_to_window(data->mlx, data->win, data->img.img_player_1, pos_x, pos_y);
// 			pos_y++;
// 		}
// 	}
// 	else if (keycode == up_k || keycode == up_a)
// 	{
// 		new_pos = pos_y - data->img.img_height;
// 		while (pos_y >= new_pos)
// 		{
// 			mlx_put_image_to_window(data->mlx, data->win, data->img.img_player_1, pos_x, pos_y);
// 			pos_y--;
// 		}
// 	}
// 	if (keycode == left_a || keycode == left_k || keycode == right_a || keycode == right_k || keycode == down_a || keycode == down_k || keycode == up_a || keycode == up_k)
// 	{
// 		data->moves++;
// 		ft_printf("Moves = %d\n", data->moves);
// 		//ft_put_score(data);
// 	}
// 	if (keycode == XK_Escape)
// 	{
// 		ft_printf("You quit the game!\n");
// 		// mlx_destroy_image(data->mlx, img->img_player_1);
// 		// mlx_destroy_image(data->mlx, img->img_wall);
// 		mlx_destroy_window(data->mlx, data->win);
// 		mlx_destroy_display(data->mlx);
// 		//free(data.mlx);
// 		exit(0);
// 	}
// 	return (0);
// }

/* Destroys images, windows and displays and frees memory */
void	ft_free(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.img_player_1);
	mlx_destroy_image(data->mlx, data->img.img_wall);
	mlx_destroy_image(data->mlx, data->img.img_ground);
	mlx_destroy_image(data->mlx, data->img.img_col_1);
	mlx_destroy_image(data->mlx, data->img.img_exit);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
}

void	ft_move_all(t_data *data, int new_x, int new_y)
{
	int	cur_x;
	int	cur_y;

	cur_x = data->coords.x / data->img.img_height;
	cur_y = data->coords.y / data->img.img_width;

	new_x = 0;
	new_y = 0;

	//data->map.map[cur_x + new_x][cur_y + new_y] = data->img.img_player_1; //->peut pas assign img au coordonne de map 
	// data->map.map[cur_x][cur_y] = data->img.img_ground;

	// cur_x = data->coords.x / 80;
	// cur_y = data->coords.y / 80;
	//Faire une condition qui verifie si la direction sur laquelle on va est un mur ou pas
	//if (data->map.map[cur_x + new_x][cur_y + new_y] == '1')
		//on swap pas
}

/* Calls move function while giving it according arguments to move the player */
int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == right_a || keycode == right_k)
		ft_move_all(data, 0, 1);
	if (keycode == left_a || keycode == left_k)
		ft_move_all(data, 0, -1);
	if (keycode == up_a || keycode == up_k)
		ft_move_all(data, 1, 0);
	if (keycode == down_a || keycode == down_k)
		ft_move_all(data, -1, 0);
	if (keycode == XK_Escape)
	{
		ft_printf("You quit the game!\n");
		ft_free(data);
		exit(0);
	}
	return (0);
}

/* Manages mouse clicks */
int	x_click(int keycode)
{
	if (keycode == 1)
		ft_printf("You used the left click!\n");
	if (keycode == 2)
		ft_printf("You pressed on the middle mouse button\n");
	if (keycode == 3)
		ft_printf("You used the right click!\n");
	if (keycode == 4)
		ft_printf("You used scrolled up!\n");
	if (keycode == 5)
		ft_printf("You used scrolled down!\n");
	return (0);
}


/* Manages window termination by clicking X */
int	cross_close(t_data *data)
{
	ft_printf("You quit the game!\n");
	ft_free(data);
	exit(1);
	return (0);
}

/* Read **map with GNL */
void    ft_maps(t_data *data)
{
	int fd;
	char *file;
	char *line;
	char *tmp;
	// int	i;

	file = "maps/test.ber";
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error while opening the map!\n");
        exit (1);
    }
	line = get_next_line(fd);
	tmp = NULL;
	while (line)
	{
		tmp = ft_sub_or_join(tmp, line);
		free(line);
		line = get_next_line(fd);
	}
    free(line);
    data->map.map = ft_split(tmp, '\n');
    // i = 0;
	// while (data->map.map[i] != NULL)
	// {
	// 	ft_printf("map = %s\n", data->map.map[i]);
	// 	i++;
	// }
	free(tmp);
}

int	main(/* int argc, char **argv */)
{
	t_data	data;

	/* if (argc != 2)
	{
		ft_printf("Too many/few arguments!");
		return (0);
	} */

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, map_size_x, map_size_y, "so_long");
	if (ft_check_mlx(&data) == 1)
		return (1);
	ft_get_images(&data);
	if (ft_check_images(&data) == 1)
		return (1);
	ft_maps(&data);
	if (ft_check_map(&data) == 1)
		return (1);
	ft_put_images_to_map(&data);
	//data.moves = 0;
	mlx_hook(data.win, 02, KeyPressMask, ft_put_images_to_map, &data);
	mlx_hook(data.win, 02, KeyPressMask, ft_key_press, &data);
	mlx_hook(data.win, 17, StructureNotifyMask, cross_close, &data);
	mlx_hook(data.win, 04, ButtonPressMask, x_click, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	return (0);
}