/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:12 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/04 13:17:52 by georgesims       ###   ########.fr       */
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

static char **map_main(char **map, t_data *data, const char  *filepath)
{
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


int pos_conditions(size_t row, size_t col, t_data *data)
{
    if (row < 0 || row > data->map_height)
        return (0);
    else if (col < 0 || col > data->map_width)
        return (0);
    else if (data->map[row][col] == '1')
        return (0);
    else if (data->map[row][col] == 'E')
    {
        mlx_destroy_window(data->mlx, data->win);
        return (1);
    }
    else if (data->map[row][col] == '0')
        return (1);
    else
        return (0);
}

// Function that takes keycode and data struct as arguments in order to implement every keypress into an event
int ft_keypress(int keycode, void *param)
{
    // Determine the new position based on the key pressed
    // Check if the new position is valid (not a wall or outside the map)
    // If the new position is valid:
    //   - Redraw the tile at the player's current position
    //   - Update the player's position in the map
    //   - Redraw the player at the new position
    size_t  row;
    size_t  col;
    t_data *data;
    
    data = (t_data *)param;
    row = data->player_pos.row;
    col = data->player_pos.col;
    if (keycode == 0) //keycode for a
    {
        printf("first if statement\n");
        if (pos_conditions(row, col - 1, data) == 1)
    	{
            data->map[row][col] = '0';
            data->map[row][col - 1] = 'P';
            //data->player_pos.x -= 1;
            printf("row: %d\n", data->player_pos.row);
            printf("col: %d\n", data->player_pos.col);
            printf("reached 'a' condition\n");
        }
    }    
    if (keycode == 13) //keycode for w
        if (pos_conditions(row - 1, col, data) == 1)
        {
            data->map[row][col] = '0';
            data->map[row - 1][col] = 'P';
            //data->player_pos.y -= 1;
            printf("row: %d\n", data->player_pos.row);
            printf("col: %d\n", data->player_pos.col);
            printf("reached 'w' condition\n");
        }
    if (keycode == 1) //keycode for s
        if (pos_conditions(row + 1, col, data) == 1)
        {
            data->map[row][col] = '0';
            data->map[row + 1][col] = 'P';
        }
    if (keycode == 2) //keycode for d
        if (pos_conditions(row, col + 1, data) == 1)
        {
            data->map[row][col] = '0';
            data->map[row][col + 1] = 'P';
        }
    if (keycode == 53) //keycode for ESC
    {
    	mlx_destroy_window(data->mlx, data->win);
        printf("ESC pressed\n");
    }
    draw_map(data->map, data);
    return (0);
}

// Main Function 
int main(int ac, char *av[])
{
    t_data      *data;

    if (ac != 2)
        return (0);
    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        return (ft_free(data));
	data->mlx = mlx_init();
    data->pixel_rate = 32;
    if (!data->mlx)
        return (ft_free(data));
    data->map = NULL;
    data->map = map_main(data->map, data, (const char *)av[1]);
    // set up key press callback
    mlx_hook(data->win, 2, 1L<<0, ft_keypress, data);
   	// loop hook for continuous rendering
    mlx_loop_hook(data->mlx, render_next_frame, data);
    // start event loop
    mlx_loop(data->mlx);
    // free map and struct to avoid leaks
    ft_free_map(data->map);
    free(data);
    return(0);
}