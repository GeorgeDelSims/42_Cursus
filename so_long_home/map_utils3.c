/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:23:28 by gsims             #+#    #+#             */
/*   Updated: 2023/12/07 11:31:34 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_map // Map check struct
{
    int  i; // rows
    int  j; // columns
}           t_map;

// REcursive part of the flood fill function
void	fill(char **map, t_map size, t_map curr, char to_fill)
{
	if (curr.j < 0 || curr.j >= size.j || curr.i < 0 || curr.i >= size.i
		|| (map[curr.j][curr.i] != to_fill && map[curr.j][curr.i] != 'C'
			&& map[curr.j][curr.i] != 'E' && map[curr.j][curr.i] != '0'))
		return ;

	map[curr.j][curr.i] = 'V';
	fill(map, size, (t_map){curr.i - 1, curr.j}, to_fill);
	fill(map, size, (t_map){curr.i + 1, curr.j}, to_fill);
	fill(map, size, (t_map){curr.i, curr.j - 1}, to_fill);
	fill(map, size, (t_map){curr.i, curr.j + 1}, to_fill);
}
//Flood fill to check path
void	flood_fill(char **map, t_map size, t_map begin)
{
	fill(map, size, begin, map[begin.j][begin.i]);
}

// Finds character within map 
static int	find_char(char **map, char c)
{
	int	row;
	int	col;
	
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col])
		{
			if (map[row][col] == c)
				return (1);
			col++;	
		}
		row++;
	}
	return (0);
}

// Prints the map for debugging
void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while(map[i][j])
		{
			ft_printf("%c ", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

// Creates a copy of the map for the path check
char	**copy_map(t_data *data)
{
	char	**mapcpy;
	int	i;

	mapcpy = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!mapcpy)
		return (NULL);
	i = 0;
	while ((size_t)i < data->map_height)
    {
        mapcpy[i] = ft_strdup(data->map[i]);
        i++;
    }
    mapcpy[i] = NULL;
    return (mapcpy);	
}

// Function that checks if there is a valid path to the Exit and all the Collectibles
int	check_path(t_data *data)
{
	char **mapcpy;
	t_map	size;
	t_map	curr;
	
	mapcpy = copy_map(data);
	if (!mapcpy)
		return (0);
	size.i = data->map_height;
	size.j = data->map_width;
	curr.i = data->player.row;
	curr.j = data->player.col;
	mapcpy[curr.i][curr.j] = '0';
	flood_fill(mapcpy, size, curr);
	if (find_char(mapcpy, 'E') == 1 || find_char(mapcpy, 'C') == 1)
	{
		ft_free_map(mapcpy);
		return (0);	
	}
	ft_free_map(mapcpy);
	return (1);
}