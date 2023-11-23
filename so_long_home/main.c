/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:12 by georgesims        #+#    #+#             */
/*   Updated: 2023/11/23 12:05:10 by gsims            ###   ########.fr       */
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
	int		x;
	int		y;
    t_image wall;
    t_image floor;
    t_image collectible;
    t_image exit;
    t_image player;
}			t_data;

// Get width in order to malloc a char** for the map 
size_t	get_width(int fd)
{
    int		bytesread;
    size_t	width;
    char	buffer[BUFFER_SIZE];
    char	*newline_pos;

    width = 0;
    while ((bytesread = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (bytesread <= 0)
            return (0);
        newline_pos = ft_strchr(buffer, '\n');
		if (newline_pos)
        {
            width += newline_pos - buffer;
            break ;
        }
        else
            width += bytesread;
	}
    return (width);
}

// Count the number of characters in a buffer
static size_t	ft_countchar_buff(char *str, char c)
{
	size_t	count;
	int		i;
	
	i = 0;
	count = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

// Get height in order to malloc a char** for the map
size_t	get_height(int fd)
{
	int		bytesread;
	size_t	height;
	char	buffer[BUFFER_SIZE];
	
	height = 0;
	while ((bytesread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (bytesread <= 0)
			return (0);
		height += ft_countchar_buff(buffer, '\n');
	}
	return (height);
}

// Function to Open the file and get it's fd to give other functions access to the file
int	get_fd(const char * filepath)
{
	int     fd;
    int     n;
    char    buf[10];
	
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		perror("Error opening file");
        return (-1);
    n = read(fd, buf, 10);
    if (n < 0)
    {
        perror("Error reading file");
        return -1;
    }
    buf[n] = '\0';
    printf("First 10 characters of file: %s\n", buf);
	return(fd);
}

// Function to get width and height of the map and allocate memory for it in a char** (this function also closes the .ber file)
    char    **read_map(int  fd)
{
    char        **map;
    size_t      i;
    size_t      j;
    char        *line;
    
    map = (char **)malloc((get_height(fd) + 1) * sizeof(char *));
    if (!map)
        return (NULL);
    i = 0;
    line = NULL;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        map[i] = (char *)malloc((get_width(fd) + 1)* sizeof(char));
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
        map[i][get_width(fd)] = '\0';
        i++;
    }
    printf("Hello\n");
    map[i] = NULL;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            printf("%d", map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
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
                printf("x : %i & y : %i \n", x, y);
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
    printf("image : %p\n width : %i\n height : %i\n", data->wall.img, data->wall.width, data->wall.height);
    data->floor.img = mlx_xpm_file_to_image(data->mlx, "./textures/water1.xpm", &data->floor.width, &data->floor.height);
    printf("image : %p\n width : %i\n height : %i\n", data->floor.img, data->floor.width, data->floor.height);
   //data->collectible.img = mlx_xpm_file_to_image(data->mlx, "./textures/collectible.xpm", &data->collectible.width, &data->collectible.height);
   //data->exit.img = mlx_xpm_file_to_image(data->mlx, "./textures/exit.xpm", &data->exit.width, &data->exit.height);
   //data->player.img = mlx_xpm_file_to_image(data->mlx, "./textures/player.xpm", &data->player.width, &data->player.height);
}

static int ft_free(void *ptr)
{
    free(ptr);
    return (-1);
}

int main()
{
    const char  *filepath = "./map.ber";
    t_data      *data;
    char        **map;
    int         fd;
    int         i;
    int         j;
    
    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        return (ft_free(data));
    fd = get_fd(filepath);
    printf("fd : %d\n", fd);
    if (fd < 0)
        return (ft_free(data));
	data->x = 32 * get_width(fd);
    printf("x dimensions : %i\n", data->x);
	data->y = 32 * get_height(fd);
    printf("y dimensions : %i\n", data->y);
	data->mlx = mlx_init();
    if (!data->mlx)
        return (ft_free(data));
	data->win = mlx_new_window(data->mlx, data->x, data->y, "so_long");
    if (!data->win)
        return (ft_free(data));
    map = read_map(fd);
    if (!map)
        return (ft_free(data));
    
    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            printf("%d", map[i][j]);
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