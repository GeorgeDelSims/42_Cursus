/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:12 by georgesims        #+#    #+#             */
/*   Updated: 2023/11/23 16:39:02 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


//Function that frees any pointer and returns -1 for error handling
static int ft_free(void *ptr)
{
    free(ptr);
    return (-1);
}

// Function frees the map iteratively (freeing each char pointer)
static void ft_free_map(char **map)
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

static char **map_main(char **map, t_data *data)
{
    const char  *filepath = "./map.ber";

    map = read_map(filepath, data);
    if (!map)
    {
        free(data);
        return (NULL);
    }
    data->win = mlx_new_window(data->mlx, 32 * data->map_width, 32 * data->map_height, "so_long");
    if (!data->win)
    {
        free(data);
        return (NULL);
    }
    init_images(data); 
    draw_map(map, data);
    return (map);
}

static int	render_next_frame(void *data)
{
	if (data)
		return (0);
	mlx_do_sync(&data);
	//continuous rendering code
	return (0);
}


int pos_conditions(size_t width, size_t height, t_data *data)
{
    if (width < 0 || width > data->map_width)
        return (0);
    else if (height < 0 || height > data->map_height)
        return (0);
    else if (data->map[width][height] == '1')
        return (0);
    else if (data->map[width][height] == 'E')
    {
        mlx_destroy_window(data->mlx, data->win);
        return (1);
    }
    else if (data->map[width][height] == '0')
        return (1);
    else
        return (0);
}

// Function that takes keycode and data struct as arguments in order to implement every keypress into an event
int ft_keypress(int keycode, t_data *data)
{
    // Determine the new position based on the key pressed
    // Check if the new position is valid (not a wall or outside the map)
    // If the new position is valid:
    //   - Redraw the tile at the player's current position
    //   - Update the player's position in the map
    //   - Redraw the player at the new position
    size_t  width;
    size_t  height;
    size_t  move;
    
    width = data->player_pos.width;
    height = data->player_pos.height;
    move = data->pixel_rate;
    if (keycode == 0) //keycode for a
        if (pos_conditions(width - move, height, data) == 1)
    	    data->player_pos.width -= data->pixel_rate;
    if (keycode == 13) //keycode for w
        if (pos_conditions(width, height + move, data) == 1)
            data->player_pos.height += data->pixel_rate;
    if (keycode == 1) //keycode for s
        if (pos_conditions(width, height - move, data) == 1)
    	    data->player_pos.height -= data->pixel_rate;
    if (keycode == 2) //keycode for d
        if (pos_conditions(width + move, height, data) == 1)
            data->player_pos.width += data->pixel_rate;
    if (keycode == 53) //keycode for ESC
    	mlx_destroy_window(data->mlx, data->win);
//    ft_draw_img(data);
    return (0);
}

// Main Function 
int main()
{
    t_data      *data;
    
    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        return (ft_free(data));
	data->mlx = mlx_init();
    data->pixel_rate = 32;
    if (!data->mlx)
        return (ft_free(data));
    data->map = NULL;
    data->map = map_main(data->map, data);
    // set up key press callback
    mlx_key_hook(data->win, ft_keypress, data);
   	// loop hook for continuous rendering
    mlx_loop_hook(data->mlx, render_next_frame, data);
    // start event loop
    mlx_loop(data->mlx);
    // free map and struct to avoid leaks
    ft_free_map(data->map);
    free(data);
    return(0);
}