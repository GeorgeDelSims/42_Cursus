/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:34:05 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/06 13:05:50 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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
t_mc    *init_map_check(t_mc *mc)
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
int         check_map(char **map)
{
    t_mc *mc;

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
        return (0);
    return (1);
}