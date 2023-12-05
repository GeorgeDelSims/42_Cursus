/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:34:05 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/05 15:38:27 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_map_check
{
    int     player;
    int     exit;
    int     collectible;
    int     i;
    int     j;
}               t_map_check;

// Function to get the length of the lines in the map
static size_t  get_line_length(int fd, size_t *row, size_t *col)
{
    char    buffer;
    size_t  line_length;

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

// Function opens the file, gets the rows and cols of the map within and closes the file. 
void    get_dimensions(const char *filepath, size_t *row, size_t *col)
{
    size_t  line_length;
    int     fd;

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return ;
    line_length = get_line_length(fd, row, col);
    // If the file doesn't end with a newline, count the last line
    if (line_length > 0)
    {
        if (line_length > *row)
            *row = line_length;
        (*col)++;
    }
    close(fd);
}


// Initialise map check struct
static t_map_check *init_map_check(t_map_check *map_check)
{
    map_check = (t_map_check *)malloc(sizeof(t_map_check));
    if (!map_check)
        return (NULL);
    map_check->player = 0;
    map_check->exit = 0;
    map_check->collectible = 0;
    map_check->i = 0;
    map_check->j = 0;
    return (map_check);
}

// Function to check if the map is valid
int         check_map(char **map)
{
    t_map_check *mc;

    mc = NULL;
    mc = init_map_check(mc);
    while (map[mc->i])
    {
        mc->j = 0;
        while (map[mc->i][mc->j])
        {
            if (map[mc->i][mc->j] != '1' && map[mc->i][mc->j] != '0' && map[mc->i][mc->j] != 'C' && map[mc->i][mc->j] != 'E' && map[mc->i][mc->j] != 'P')
                return (0);
            if (map[mc->i][mc->j] == 'P')
                mc->player++;
            if (map[mc->i][mc->j] == 'E')
                mc->exit++;
            if (map[mc->i][mc->j] == 'C')
                mc->collectible++;
            mc->j++;
        }
        mc->i++;
    }
    if (mc->player != 1 || mc->exit != 1 || mc->collectible == 0)
        return (0);
    return (1);
}