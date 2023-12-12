/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:03:15 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/12 13:36:02 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function that checks if there are still collectibles on the map
static int	check_map_collect(char **map)
{
	int	i;
	int	j;
	int	collect;

	i = 0;
	collect = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				collect++;
			j++;
		}
		i++;
	}
	if (collect == 0)
		return (0);
	return (1);
}

// Function that checks the conditions of the next position of the player
int	pos_conditions(size_t row, size_t col, t_data *data)
{
	if (row < 0 || row >= data->map_height)
		return (0);
	else if (col < 0 || col >= data->map_width)
		return (0);
	else if (data->map[row][col] == '1')
		return (0);
	else if (data->map[row][col] == 'E')
	{
		if (check_map_collect(data->map) == 0)
		{
			mlx_destroy_window(data->mlx, data->win);
			exit(0);
			return (1);
		}
		else
			return (0);
	}
	else if (data->map[row][col] == 'C')
		return (1);
	else if (data->map[row][col] == '0')
		return (1);
	else
		return (0);
}

// Function that takes keycode and data struct as arguments
// in order to implement every keypress into an event
int	ft_keypress(int keycode, void *param)
{
	size_t	row;
	size_t	col;
	t_data	*data;

	data = (t_data *)param;
	if (!data)
		return (0);
	row = data->player_pos.row;
	col = data->player_pos.col;
	if (keycode == 0)
		data->count += move_left(row, col, data);
	if (keycode == 13)
		data->count += move_up(row, col, data);
	if (keycode == 1)
		data->count += move_down(row, col, data);
	if (keycode == 2)
		data->count += move_right(row, col, data);
	if (keycode == 53)
		return (escape(data));
	draw_map(data->map, data);
	return (0);
}
