/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:56:30 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/12 11:43:14 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to malloc the rows in the map and
// fill them with the characters in the .ber file
static char	**malloc_and_fill_map(char **map, t_data *data, int fd)
{
	size_t	row;
	char	*line;

	row = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		map[row] = ft_strdup(line);
		map[row][data->map_width] = '\0';
		row++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	map[row] = NULL;
	return (map);
}

// Main function that allocates memory for the map and
// reads the map from the .ber file
char	**read_map(const char *filepath, t_data *data)
{
	char	**map;
	int		fd;

	get_dimensions(filepath, &data->map_width, &data->map_height);
	map = (char **)malloc((data->map_height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		ft_free_map(map);
		return (NULL);
	}
	map = malloc_and_fill_map(map, data, fd);
	close(fd);
	return (map);
}

void	put_img(t_data data, int row, int col, t_image img)
{
	mlx_put_image_to_window(data.mlx, data.win, img.img, col * data.pixel_rate,
		row * data.pixel_rate);
}

// Function to draw the map according to the characters in the .ber file
void	draw_map(char **map, t_data *data)
{
	int	row;
	int	col;

	mlx_clear_window(data->mlx, data->win);
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			put_img(*data, row, col, data->floor);
			if (map[row][col] == '1')
				put_img(*data, row, col, data->wall);
			else if (map[row][col] == 'C')
				put_img(*data, row, col, data->collectible);
			else if (map[row][col] == 'E')
				put_img(*data, row, col, data->exit);
			else if (map[row][col] == 'P')
				put_img(*data, row, col, data->player);
			col++;
		}
		row++;
	}
}

// Function to initialize the images
void	init_images(t_data *data)
{
	data->wall.img = mlx_xpm_file_to_image(data->mlx, "./textures/tile044.xpm",
			&data->wall.row, &data->wall.col);
	data->floor.img = mlx_xpm_file_to_image(data->mlx, "./textures/tile004.xpm",
			&data->floor.row, &data->floor.col);
	data->collectible.img = mlx_xpm_file_to_image(data->mlx,
			"./textures/brain.xpm", &data->collectible.row,
			&data->collectible.col);
	data->exit.img = mlx_xpm_file_to_image(data->mlx, "./textures/tile036.xpm",
			&data->exit.row, &data->exit.col);
	data->player.img = mlx_xpm_file_to_image(data->mlx,
			"./textures/mutant2.xpm", &data->player.row, &data->player.col);
}
