/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquerel <kquerel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:56:10 by kquerel           #+#    #+#             */
/*   Updated: 2023/03/17 22:11:22 by kquerel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/* Read map with GNL */
void	ft_read_maps(t_data *data)
{
	int		fd;
	char	*file;
	char	*line;
	char	*tmp;

	file = "maps/1.ber";
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCan't open the map!\n");
		ft_free(data);
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

/* Main function */
//gerer les arguments + parser le nom du fichier (ft_strstr)
int	main(/* int argc, char **argv */)
{
	t_data	data;

	/* if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments!");
		return (0);
	} */

	data.count.counter = 0;
	data.count.moves = 0;
	data.count.score = 0;
	ft_read_maps(&data);
	ft_check_map_contents(&data);
	ft_check_map_format(&data);
	data.mlx = mlx_init();
	ft_check_mlx(&data);
	data.win = mlx_new_window(data.mlx, data.map.map_y * 80,
			data.map.map_x * 80, "so_long");
	ft_check_mlx_win(&data);
	ft_get_images(&data);
	ft_check_images(&data);
	ft_put_images_to_map(&data);
	ft_put_score(&data);
	mlx_hook(data.win, 02, KeyPressMask, ft_put_images_to_map, &data);
	mlx_hook(data.win, 02, KeyPressMask, ft_key_press, &data);
	mlx_hook(data.win, 17, StructureNotifyMask, cross_close, &data);
	mlx_loop(data.mlx);
	//mlx_destroy_display(data.mlx);
	return (0);
}
