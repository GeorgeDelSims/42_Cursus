/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:56:30 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/04 13:16:37 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function opens the file, gets the y and x of the map within and closes the file. 
void    get_dimensions(const char *filepath, size_t *x, size_t *y)
{
    int     fd;
    char    buffer;
    size_t  line_length;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return ;
    line_length = 0;
    *x = 0;
    *y = 0;
    while (read(fd, &buffer, 1) > 0)
    {
        if (buffer == '\n')
        {
            if (line_length > *x)
                *x = line_length;
            line_length = 0;
            (*y)++;
        }
        else
            line_length++;
    }
    // If the file doesn't end with a newline, count the last line
    if (line_length > 0)
    {
        if (line_length > *x)
            *x = line_length;
        (*y)++;
    }
    close(fd);
}

// Function to get x and y of the map and allocate memory for it in a char** (this function also closes the .ber file)
char    **read_map(const char *filepath, t_data *data)
{
    char        **map;
    size_t      row;
    char        *line;
    int         fd;
    
    // get dimensions and malloc array of pointers
    get_dimensions(filepath, &data->map_width, &data->map_height);
    map = (char **)malloc((data->map_height + 1) * sizeof(char *));
    if (!map)
        return (NULL);
    // Open file again to get fd
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
    {
        free(map);
        return (NULL);
    }
    // loop over array of pointers and malloc each pointer to the correct size 
    row = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map[row] = (char *)malloc((data->map_width + 1)* sizeof(char));
        if (!map[row])
        {
            while (row > 0)
            {
                row--;
                free(map[row]);
            }
            free(map);
            return (NULL);
        }
        map[row] = ft_strdup(line);
        map[row][data->map_width] = '\0';
        row++;
    }
    map[row] = NULL;
    close(fd);
    return (map);
}

// Function to draw the map according to the characters in the .ber file
void    draw_map(char **map, t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
    int     row;
    int     col;
    
    row = 0;
    while (map[row])
    {
        col = 0;
        while (map[row][col])
        {
            if (map[row][col] == '1')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->wall.img, col * data->pixel_rate, row * data->pixel_rate);
//            else if (map[row][col] == 'C')
//                mlx_put_image_to_window(data->mlx, data->win, data.collectible, x, y);
			}
			else if (map[row][col] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit.img, col * data->pixel_rate, row * data->pixel_rate);
            else if (map[row][col] == 'P')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->player.img, col * data->pixel_rate, row * data->pixel_rate);
                data->player_pos.col = col;
                data->player_pos.row = row;
                printf("player pos x : %d, y : %d\n", data->player_pos.row, data->player_pos.col);
            }
            else if (map[row][col] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->floor.img, col * data->pixel_rate, row * data->pixel_rate);
            col++;
        }
        row++;
    }
}

// Function to initialize the images

void    init_images(t_data *data)
{
    data->wall.img = mlx_xpm_file_to_image(data->mlx, "./textures/grass.xpm", &data->wall.row, &data->wall.col);
    data->floor.img = mlx_xpm_file_to_image(data->mlx, "./textures/water1.xpm", &data->floor.row, &data->floor.col);
   //data->collectible.img = mlx_xpm_file_to_image(data->mlx, "./textures/collectible.xpm", &data->collectible.x, &data->collectible.y);
	data->exit.img = mlx_xpm_file_to_image(data->mlx, "./textures/tree.xpm", &data->exit.row, &data->exit.col);
	data->player.img = mlx_xpm_file_to_image(data->mlx, "./textures/KingKong.xpm", &data->player.row, &data->player.col);
}
