/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:12 by georgesims        #+#    #+#             */
/*   Updated: 2023/11/23 14:34:24 by gsims            ###   ########.fr       */
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
	size_t	map_height;
	size_t	map_width;
    t_image wall;
    t_image floor;
    t_image collectible;
    t_image exit;
    t_image player;
}			t_data;

// Function opens the file, gets the height and width of the map within and closes the file. 
void    get_dimensions(const char *filepath, size_t *width, size_t *height)
{
    int     fd;
    char    buffer;
    size_t  line_length;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return ;
    line_length = 0;
    *width = 0;
    *height = 0;
    while (read(fd, &buffer, 1) > 0)
    {
        if (buffer == '\n')
        {
            if (line_length > *width)
                *width = line_length;
            line_length = 0;
            (*height)++;
        }
        else
            line_length++;
    }
    // If the file doesn't end with a newline, count the last line
    if (line_length > 0)
    {
        if (line_length > *width)
            *width = line_length;
        (*height)++;
    }
    close(fd);
}
//Function that frees any pointer and returns -1 for error handling
static int ft_free(void *ptr)
{
    free(ptr);
    return (-1);
}

// Function to get width and height of the map and allocate memory for it in a char** (this function also closes the .ber file)
    char    **read_map(const char *filepath, t_data *data)
{
    char        **map;
    size_t      i;
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
    i = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        map[i] = (char *)malloc((data->map_width + 1)* sizeof(char));
        if (!map[i])
        {
            while (i > 0)
            {
                i--;
                free(map[i]);
            }
            free(map);
            return (NULL);
        }
        map[i] = ft_strdup(line);
        map[i][data->map_width] = '\0';
        i++;
    }
    map[i] = NULL;
    close(fd);
    return (map);
}

// Function to draw the map according to the characters in the .ber file
void    draw_map(char **map, t_data *data)
{
    mlx_clear_window(data->mlx, data->win);
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
        x = 0;
        while (map[i][j])
        {
            if (map[i][j] == '1')
            {
                mlx_put_image_to_window(data->mlx, data->win, data->wall.img, x, y);
//            else if (map[i][j] == 'C')
//                mlx_put_image_to_window(data->mlx, data->win, data.collectible, x, y);
//            else if (map[i][j] == 'E')
//                mlx_put_image_to_window(data->mlx, data->win, data.exit, x, y);
//            else if (map[i][j] == 'P')
//                mlx_put_image_to_window(data->mlx, data->win, data.player, x, y);
            }
            else if (map[i][j] == '0')
                mlx_put_image_to_window(data->mlx, data->win, data->floor.img, x, y);
            j++;
            x += 32;
        }
        i++;
        y += 32;
    }
}

// Function to initialize the images

void    init_images(t_data *data)
{
    data->wall.img = mlx_xpm_file_to_image(data->mlx, "./textures/grass.xpm", &data->wall.width, &data->wall.height);
    data->floor.img = mlx_xpm_file_to_image(data->mlx, "./textures/water1.xpm", &data->floor.width, &data->floor.height);
   //data->collectible.img = mlx_xpm_file_to_image(data->mlx, "./textures/collectible.xpm", &data->collectible.width, &data->collectible.height);
   //data->exit.img = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm", &data->exit.width, &data->exit.height);
   //data->player.img = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm", &data->player.width, &data->player.height);
}

int main()
{
    const char  *filepath = "./map.ber";
    t_data      *data;
    char        **map;
    int         i;
    int         j;
    
    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        return (ft_free(data));
	data->mlx = mlx_init();
    if (!data->mlx)
        return (ft_free(data));
    map = read_map(filepath, data);
    if (!map)
        return (ft_free(data));
    data->win = mlx_new_window(data->mlx, 32 * data->map_width, 32 * data->map_height, "so_long");
    if (!data->win)
        return (ft_free(data));
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            printf("%c", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
    init_images(data); 
    draw_map(map, data);
    mlx_loop(data->mlx);
    i = 0;
    while (map[i]) // free map 
    {
        free(map[i]);
        i++;
    }
    free(map);
    free(data);
    return(0);
}