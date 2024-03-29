/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:34:05 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/12 11:54:51 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Function to get the length of the lines in the map
static size_t	get_line_length(int fd, size_t *row, size_t *col)
{
	char	buffer;
	size_t	line_length;

	line_length = 0;
	*row = 0;
	*col = 0;
	while (read(fd, &buffer, 1) > 0)
	{
		if (buffer == '\n')
		{
			if (line_length > *row)
				*row = line_length;
			line_length = 0;
			(*col)++;
		}
		else
			line_length++;
	}
	return (line_length);
}

// Function opens the file, gets the dimensions of the map
void	get_dimensions(const char *filepath, size_t *row, size_t *col)
{
	size_t	line_length;
	int		fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return ;
	line_length = get_line_length(fd, row, col);
	if (line_length > 0)
	{
		if (line_length > *row)
			*row = line_length;
		(*col)++;
	}
	close(fd);
}

// Function to initialize the images
static t_mc	init_mc(void)
{
	t_mc	mc;

	mc.p = 0;
	mc.e = 0;
	mc.c = 0;
	mc.i = 0;
	mc.j = 0;
	return (mc);
}

// Function to check char and shorten check_map
static int	check_char(char **map, int row, int col)
{
	if (map[row][col] != '1' && map[row][col] != '0' && map[row][col] != 'C'
		&& map[row][col] != 'E' && map[row][col] != 'P')
		return (0);
	return (1);
}

// Function to check if the map is valid
int	check_map(char **map)
{
	t_mc	mc;

	mc = init_mc();
	while (map[mc.i])
	{
		mc.j = 0;
		while (map[mc.i][mc.j])
		{
			if (check_char(map, mc.i, mc.j) == 0)
				return (0);
			if (map[mc.i][mc.j] == 'P')
				mc.p++;
			if (map[mc.i][mc.j] == 'E')
				mc.e++;
			if (map[mc.i][mc.j] == 'C')
				mc.c++;
			mc.j++;
		}
		mc.i++;
	}
	if (mc.p != 1 || mc.e != 1 || mc.c == 0)
		return (0);
	return (1);
}

/*
// Function to check if the map is valid
int	check_map(char **map)
{
	int	p;
	int	e;
	int	c;
	int	i;
	int	j;

	p = 0;
	e = 0;
	c = 0;
	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'C'
				&& map[i][j] != 'E' && map[i][j] != 'P')
				return (0);
			if (map[i][j] == 'P')
				p++;
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	if (p != 1 || e != 1 || c == 0)
		return (0);
	return (1);
}
*/

/*
t_mc	*init_map_check(t_mc *mc)
{
	mc = (t_mc *)malloc(sizeof(t_mc));
	if (!mc)
		return (NULL);
	mc->P = 0;
	mc->E = 0;
	mc->C = 0;
	mc->i = 0;
	mc->j = 0;
	return (mc);
}

// Function to check if the map is valid
int	check_map(char **map)
{
	t_mc	*mc;

	mc = NULL;
	mc = init_map_check(mc);
	while (map[mc->i])
	{
		mc->j = 0;
		while (map[mc->i][mc->j])
		{
			if (map[mc->i][mc->j] != '1' && map[mc->i][mc->j] != '0'
				&& map[mc->i][mc->j] != 'C' && map[mc->i][mc->j] != 'E'
				&& map[mc->i][mc->j] != 'P')
			{
				free(mc);
				mc = NULL;
				return (0);
			}
			if (map[mc->i][mc->j] == 'P')
				mc->P++;
			if (map[mc->i][mc->j] == 'E')
				mc->E++;
			if (map[mc->i][mc->j] == 'C')
				mc->C++;
			mc->j++;
		}
		mc->i++;
	}
	if (mc->P != 1 || mc->E != 1 || mc->C == 0)
	{
		free(mc);
		mc = NULL;
		return (0);
	}
	free(mc);
	mc = NULL;
	return (1);
}
*/