/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:59:34 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/12 11:43:04 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Function that frees any pointer and returns -1 for error handling
int ft_free(void *ptr)
{
    free(ptr);
    return (-1);
}

// Function frees the map iteratively (freeing each char pointer)
void ft_free_map(char **map)
{
    int i;
    i = 0;
    while (map[i]) 
    {
        free(map[i]);
        i++;
    }
    free(map); 
}

// Function that does nothing and allows mlx_loop_hook to render the next frame
int	render_next_frame(void *data)
{
	if (data)
		return (0);
	return (0);
}

// Function to handle window close event
int handle_close(t_data *data)
{
    mlx_destroy_image(data->mlx, data->wall.img);
    mlx_destroy_image(data->mlx, data->floor.img);
    mlx_destroy_image(data->mlx, data->collectible.img);
    mlx_destroy_image(data->mlx, data->exit.img);
    mlx_destroy_image(data->mlx, data->player.img);
    ft_free_map(data->map);
    ft_free(data);
    exit(0);
}

// Function to find the player position for the map
void	find_player_pos(t_data *data)
{
	size_t	row;
	size_t	col;

	row = 0;
	while (data->map[row])
	{
		col = 0;
		while (data->map[row][col])
		{
			if (data->map[row][col] == 'P')
			{
				data->player.row = row;
				data->player.col = col;
				data->player_pos.row = row;
				data->player_pos.col = col;
				return ;
			}
			col++;
		}
		row++;
	}
}