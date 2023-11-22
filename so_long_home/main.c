/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:12 by georgesims        #+#    #+#             */
/*   Updated: 2023/11/22 20:43:59 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_image {
    void    *img;
    int     width;
    int     height;
}			t_image;

typedef struct s_data {
    void    *mlx;
    void	*win;
    t_image wall;
    t_image floor;
    t_image collectible;
    t_image exit;
    t_image player;
}			t_data;


// Function to get width and height of the map and allocate memory for it in a char**
char    **read_map(char *filepath)
{
    int         fd;
    char        **map;
    size_t      i;
    char        *line;
    
    fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (0);
    map = (char **)malloc((get_height(fd) + 1) * sizeof(char *));
    if (!map)
        return (NULL);
    i = 0; 
    while (line == get_next_line(fd))
    {
        map[i] = (char *)malloc((get_width(fd) + 1)* sizeof(char));
        map[i] = line;
        map[i][get_width(fd)] = '\0';
        i++;
    }
    map[i] = NULL;
    return (map);
}

// Function to draw the map according to the characters in the .ber file
void    draw_map(char **map)
{
    mlx_clear_window(data.mlx, data.win);
    int     i;
    int     j;
    int     x;
    int     y;
    
    i = 0;
    x = 0;
    y = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
                mlx_put_image_to_window(data.mlx, data.win, data.wall, x, y);
            else if (map[i][j] == 'C')
                mlx_put_image_to_window(data.mlx, data.win, data.collectible, x, y);
            else if (map[i][j] == 'E')
                mlx_put_image_to_window(data.mlx, data.win, data.exit, x, y);
            else if (map[i][j] == 'P')
                mlx_put_image_to_window(data.mlx, data.win, data.player, x, y);
            else if (map[i][j] == '0')
                mlx_put_image_to_window(data.mlx, data.win, data.floor, x, y);
            j++;
            x += 64;
        }
        i++;
        y += 64;
    }
}

// Function to initialize the images

void    init_images(t_data *data)
{
    data->wall.img = mlx_xpm_file_to_image(data->mlx, "./textures/wall.xpm", &data->wall.width, &data->wall.height);
    data->floor.img = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm", &data->floor.width, &data->floor.height);
    data->collectible.img = mlx_xpm_file_to_image(data->mlx, "./textures/collectible.xpm", &data->collectible.width, &data->collectible.height);
    data->exit.img = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm", &data->exit.width, &data->exit.height);
    data->player.img = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm", &data->player.width, &data->player.height);
}

int main()
{
    const char  *filepath = "./map2.ber";
    t_data      data;
    char        **map;
    
    
    
    return(res);
}