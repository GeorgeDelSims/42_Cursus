/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:56:30 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/07 11:49:15 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to malloc the rows in the map and 
// fill them with the characters in the .ber file

static char    **malloc_and_fill_map(char **map, t_data *data, int fd)
{
    size_t      row;
    char        *line;
    
    row = 0;
    while ((line = get_next_line(fd)) != NULL) // loop over array of pointers 
    {
        map[row] = ft_strdup(line); // malloc and copy content of each line 
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
        map[row][data->map_width] = '\0';
        row++;
    }
    map[row] = NULL;
    return (map);
}

// Function to find the player position for the map
void	find_player_pos(t_data	*data)
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

// Main function that allocates memory for the map and reads the map from the .ber file
char    **read_map(const char *filepath, t_data *data)
{
    char        **map;
    int         fd;
    
    // get dimensions and malloc array of pointers
    get_dimensions(filepath, &data->map_width, &data->map_height);
    map = (char **)malloc((data->map_height + 1) * sizeof(char *));
    if (!map)
        return (NULL);
    // Open file to get fd
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
    {
        ft_free_map(map);
        return (NULL);  
    }
    // Malloc and fill map
    map = malloc_and_fill_map(map, data, fd);
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
            mlx_put_image_to_window(data->mlx, data->win, data->floor.img, col * data->pixel_rate, row * data->pixel_rate);
            if (map[row][col] == '1')
                mlx_put_image_to_window(data->mlx, data->win, data->wall.img, col * data->pixel_rate, row * data->pixel_rate);
            else if (map[row][col] == 'C')
                mlx_put_image_to_window(data->mlx, data->win, data->collectible.img, col * data->pixel_rate, row * data->pixel_rate);
		    else if (map[row][col] == 'E')
                mlx_put_image_to_window(data->mlx, data->win, data->exit.img, col * data->pixel_rate, row * data->pixel_rate);
            else if (map[row][col] == 'P')
                mlx_put_image_to_window(data->mlx, data->win, data->player.img, col * data->pixel_rate, row * data->pixel_rate);
            col++;
        }
        row++;
    }
}

// Function to initialize the images
void    init_images(t_data *data)
{
    data->wall.img = mlx_xpm_file_to_image(data->mlx,
    "./textures/tile044.xpm", &data->wall.row, &data->wall.col);
    data->floor.img = mlx_xpm_file_to_image(data->mlx,
    "./textures/tile004.xpm", &data->floor.row, &data->floor.col);
    data->collectible.img = mlx_xpm_file_to_image(data->mlx,
    "./textures/brain.xpm", &data->collectible.row, &data->collectible.col);
	data->exit.img = mlx_xpm_file_to_image(data->mlx,
    "./textures/tile036.xpm", &data->exit.row, &data->exit.col);
	data->player.img = mlx_xpm_file_to_image(data->mlx,
    "./textures/mutant2.xpm", &data->player.row, &data->player.col);
}