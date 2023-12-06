/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 10:23:28 by gsims             #+#    #+#             */
/*   Updated: 2023/12/06 17:10:43 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_map // Map check struct
{
    int  i; // rows
    int  j; // columns
}           t_map;


static int	acceptable_chars(char **map, size_t i, size_t j)
{
	if (map[i][j] == '0' || map[i][j] == 'C' || map[i][j] == 'E')
		return (1);
	else
		return (0);
}

void	fill(char **map, t_map size, t_map curr, char to_fill)
{
	if (curr.j < 0 || curr.j >= size.j || curr.i < 0 || curr.i >= size.i|| map[curr.j][curr.i] != to_fill)
		return ;

	map[curr.j][curr.i] = 'P';
	fill(map, size, (t_map){curr.i - 1, curr.j}, to_fill);
	fill(map, size, (t_map){curr.i + 1, curr.j}, to_fill);
	fill(map, size, (t_map){curr.i, curr.j - 1}, to_fill);
	fill(map, size, (t_map){curr.i, curr.j + 1}, to_fill);
}

void	flood_fill(char **map, t_map size, t_map begin)
{
	fill(map, size, begin, map[begin.j][begin.i]);
}
static int	find_char(char **map, char c)
{
	int	row;
	int	col;
	
	row = 0;
	col = 0;
	while (map[row])
	{
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

int	check_path(t_data *data)
{
	char **mapcpy;
	t_map	size;
	t_map	curr;
	
	mapcpy = copy_map(data);
	print_map(mapcpy);
	size.i = data->map_height;
	size.j = data->map_width;
	ft_printf("size.i : %d\n", size.i);
	ft_printf("size.j : %d\n", size.j);
	curr.i = data->player.row;
	curr.j = data->player.col;
	ft_printf("curr.i : %d\n", curr.i);
	ft_printf("curr.j : %d\n", curr.j);
	mapcpy[curr.i][curr.j] = '0';
	flood_fill(mapcpy, size, curr);
	print_map(mapcpy);
	if (find_char(mapcpy, 'E') == 1 || find_char(mapcpy, 'C') == 1)
	{
		free(mapcpy);
		return (1);	
	}
	free(mapcpy);
	return (0);
}

/*
int	check_path(t_data *data, const char *filepath)
{
	char	**maptest;
	t_map	*size;
	t_map	*curr;
	size_t	i;
	size_t	j;
	
	size = NULL;
	curr = NULL;
	size = init_map_check(size);
	curr = init_map_check(curr);
	if (!(maptest = read_map(filepath, data)))
	{
		free(data);
		return (0);
	}
	draw_map(maptest, data);
	get_dimensions(filepath, &size->i, &size->j);
	if (find_char(maptest, curr->i, curr->j, 'P') == 1)
	{
		print_map(maptest);
		flood_fill(maptest, *size, *curr);
		print_map(maptest);
	}
	i = 0;
	j = 0;
	if (find_char(maptest, i, j, 'C') == 0 && find_char(maptest, i, j, 'E') == 0)
		return (1);
	return (0);
} */