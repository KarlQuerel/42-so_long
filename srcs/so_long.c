/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:56:10 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/09 19:18:48 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// backtracking ?

#include "../includes/so_long.h"

/* Displays score, moves and fixed text on the window */
void	ft_put_score(t_data *data)
{
	char	*move_or_score;
	char	*final_text;

	move_or_score = ft_itoa(data->count.moves);
	final_text = ft_strjoin("MOVES = ", move_or_score);
	mlx_set_font(data->mlx, data->win, "10x20");
	mlx_string_put(data->mlx, data->win, 80, 40, 0x00BFFF, final_text);
	move_or_score = ft_itoa(data->count.score);
	final_text = ft_strjoin("CHOCOLATES = ", move_or_score);
	mlx_string_put(data->mlx, data->win, 80, 60, 0x5FFB17, final_text);
	mlx_string_put(data->mlx, data->win, map_size_x / 7, 40, 0xDAEE01, "KARL IS HUNGRY...");
	mlx_string_put(data->mlx, data->win, map_size_x / 5, 60, 0x5FFB17, "FEED HIM!");
	free(move_or_score);
	free(final_text);
	ft_check_col(data);
}

/* Destroys images, windows and displays and frees memory */
void	ft_free(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img.player_1);
	mlx_destroy_image(data->mlx, data->img.wall);
	mlx_destroy_image(data->mlx, data->img.ground);
	mlx_destroy_image(data->mlx, data->img.col_1);
	mlx_destroy_image(data->mlx, data->img.exit_closed);
	mlx_destroy_image(data->mlx, data->img.exit_open);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	//free(data->win); ??
}

/* Swaps a "ground" tile and the player position. New positions are given by the ft_key_press function and checks if the swap is possible or not */
void	ft_move(t_data *data, int new_x, int new_y)
{
	int	cur_x;
	int	cur_y;
	
	cur_x = data->coords.x / data->img.height;
	cur_y = data->coords.y / data->img.width;
	if (data->map.map[cur_x + new_x][cur_y + new_y] == '0')
	{
		data->map.map[cur_x + new_x][cur_y + new_y] = 'P';
		data->map.map[cur_x][cur_y] = '0';
		data->count.moves++;
	}
	else if(data->map.map[cur_x + new_x][cur_y + new_y] == 'C')
	{
		data->map.map[cur_x + new_x][cur_y + new_y] = 'P';
		data->map.map[cur_x][cur_y] = '0';
		data->count.score++;
		data->count.col--;
		data->count.moves++;
	}
	else if (data->map.map[cur_x + new_x][cur_y + new_y] == 'E' && data->count.col == 0)
		ft_game_success(data);
	ft_put_images_to_map(data);
}

/* Calls move function while giving it according arguments to move the player and handles window closing when pressing ESC */
int	ft_key_press(int keycode, t_data *data)
{
	if (keycode == RIGHT_K || keycode == D_K)
		ft_move(data, 0, 1);
	if (keycode == LEFT_K || keycode == A_K)
		ft_move(data, 0, -1);
	if (keycode == UP_K || keycode == W_K)
		ft_move(data, -1, 0);
	if (keycode == DOWN_K || keycode == S_K)
		ft_move(data, 1, 0);
	if (keycode == RIGHT_K || keycode == D_K || keycode == LEFT_K || keycode == A_K ||
		keycode == UP_K || keycode == W_K || keycode == DOWN_K || keycode == S_K)
		ft_put_score(data);
	if (keycode == XK_Escape)
	{
		ft_printf("You quit the game!\n");
		ft_free(data);
		exit(1);
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

	file = "maps/test.ber";
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error\nCan't open the map!\n");
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
	free(tmp);
}

int	main(/* int argc, char **argv */)
{
	t_data	data;

	/* if (argc < 2)
	{
		ft_printf("Error\nToo few arguments!");
		return (0);
	}
	else if (argc > 2)
	{
		ft_printf("Error\nToo many arguments!");
		return (0);
	} */

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, map_size_x, map_size_y, "so_long");
	ft_check_all_mlx(&data);
	ft_maps(&data);
	ft_check_map_contents(&data);
	ft_check_map_format(&data);
	ft_get_images(&data);
	ft_put_images_to_map(&data);
	ft_check_images(&data);
	ft_put_score(&data);
	data.count.moves = 0;
	data.count.score = 0;
	mlx_hook(data.win, 02, KeyPressMask, ft_put_images_to_map, &data);
	mlx_hook(data.win, 02, KeyPressMask, ft_key_press, &data);
	mlx_hook(data.win, 17, StructureNotifyMask, cross_close, &data);
	mlx_hook(data.win, 04, ButtonPressMask, x_click, &data);
	mlx_loop(data.mlx);
	mlx_destroy_display(data.mlx);
	return (0);
}