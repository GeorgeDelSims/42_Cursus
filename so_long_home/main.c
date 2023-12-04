/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:12 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/04 15:30:07 by georgesims       ###   ########.fr       */
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

// Function regrouping all the map reading and image drawing functions
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
    //printf("before map is checked\n");
    //if (check_map(data) == 0)
    //{
    //    ft_free_map(map);
    //    free(data);
    //    printf("Error\nInvalid map\n");
    //    return (NULL);
    //}
    printf("after map is checked\n");
    init_images(data);
    draw_map(map, data);
    return (map);
}

// Function that renders the next frame
static int	render_next_frame(void *data)
{
	if (data)
		return (0);
	mlx_do_sync(&data);
	//continuous rendering code
	return (0);
}

// Function that checks if there are still collectibles on the map
static int check_map_collect(char **map)
{
    int i;
    int j;
    int collect;

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
        if (check_map_collect(data->map) == 0)
        {
            mlx_destroy_window(data->mlx, data->win);
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

// Function that takes keycode and data struct as arguments in order to implement every keypress into an event
int ft_keypress(int keycode, void *param)
{
    size_t  row;
    size_t  col;
    t_data *data;
    
    data = (t_data *)param;
    row = data->player_pos.row;
    col = data->player_pos.col;
    if (keycode == 0) //keycode for a
    {
        if (pos_conditions(row, col - 1, data) == 1)
    	{
            data->map[row][col] = '0';
            data->map[row][col - 1] = 'P';
            data->count++;
        }
    }    
    if (keycode == 13) //keycode for w
        if (pos_conditions(row - 1, col, data) == 1)
        {
            data->map[row][col] = '0';
            data->map[row - 1][col] = 'P';
            data->count++;        
        }
    if (keycode == 1) //keycode for s
        if (pos_conditions(row + 1, col, data) == 1)
        {
            data->map[row][col] = '0';
            data->map[row + 1][col] = 'P';
            data->count++;       
        }
    if (keycode == 2) //keycode for d
        if (pos_conditions(row, col + 1, data) == 1)
        {
            data->map[row][col] = '0';
            data->map[row][col + 1] = 'P';
            data->count++;        
        }
    if (keycode == 53) //keycode for ESC
        mlx_destroy_window(data->mlx, data->win);
    printf("movement count : %d\n", data->count);
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
    data->count = 0;
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