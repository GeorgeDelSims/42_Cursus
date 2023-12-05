/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:12 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/05 13:01:02 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function regrouping all the map reading and image drawing functions
static char **map_main(char **map, t_data *data, const char  *filepath)
{
    map = read_map(filepath, data);
    if (!map)
    {
        free(data);
        return (NULL);
    }
    data->win = mlx_new_window(data->mlx, data->pixel_rate * data->map_width, data->pixel_rate * data->map_height, "so_long");
    if (!data->win)
    {
        free(data);
        return (NULL);
    }
    if (check_map(map) == 0)
    {
        mlx_destroy_window(data->mlx, data->win);
        printf("Error : Invalid map\n");
        return (NULL);
    }
    init_images(data);
    draw_map(map, data);
    return (map);
}

// Main Function 
int main(int ac, char *av[])
{
    t_data      *data;

    if (ac != 2)
        return (0);
    if (!(data = (t_data *)malloc(sizeof(t_data))))
        return (-1);
	data->mlx = mlx_init();
    data->pixel_rate = 32;
    if (!data->mlx)
        return (ft_free(data));
    data->map = NULL;
    if (!(data->map = map_main(data->map, data, (const char *)av[1])))
        return (ft_free(data));
    data->count = 0;
    mlx_hook(data->win, 2, 1L<<0, ft_keypress, data); // set up keypress hook
    mlx_hook(data->win, 17, 1L<<0, handle_close, data); // Set up window close hook
    mlx_loop_hook(data->mlx, render_next_frame, data); // loop hook for continuous rendering
    mlx_loop(data->mlx);    // start event loop
    ft_free_map(data->map); // free map and struct to avoid leaks
    ft_free(data);
    return (0);
}