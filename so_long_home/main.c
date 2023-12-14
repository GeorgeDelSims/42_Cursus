/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:12 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/14 10:28:41 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function regrouping all the map reading and image drawing functions
void	map_main(t_data *data)
{
	data->count = 0;
	data->win = mlx_new_window(data->mlx, data->pixel_rate * data->map_width,
			data->pixel_rate * data->map_height, "so_long");
	if (!data->win)
	{
		ft_free_map(data->map);
		free(data);
		return ;
	}
	init_images(data);
	draw_map(data->map, data);
}

void	mlx_main(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, ft_keypress, data);
	mlx_hook(data->win, 17, 1L << 0, handle_close, data);
	mlx_loop_hook(data->mlx, render_next_frame, data);
	mlx_loop(data->mlx);
}

static int	invalid_map(t_data *data)
{
	ft_printf("Error\nInvalid map\n");
	ft_free_map(data->map);
	free(data);
	return (0);
}

static int	map_checks(t_data *data)
{
	if (check_map(data->map) == 0)
		return (0);
	ft_printf("check map = %d\n", check_map(data->map));
	find_player_pos(data);
	if (check_edges(data) == 0)
		return (0);
	ft_printf("check edges = %d\n", check_edges(data));
	if (check_path(data) == 0)
		return (0);
	ft_printf("check path = %d\n", check_path(data));
	return (1);
}

// Main Function
int	main(int ac, char *av[])
{
	t_data	*data;

	if (ac != 2)
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (-1);
	data->pixel_rate = 64;
	data->map = read_map(av[1], data);
	if (!data->map)
		return (ft_free(data));
	if (map_checks(data) == 0)
		return (invalid_map(data));
	data->mlx = mlx_init();
	if (!data->mlx)
		return (ft_free(data));
	map_main(data);
	mlx_main(data);
	ft_free_map(data->map);
	free(data);
	return (0);
}
