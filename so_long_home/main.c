/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 10:44:12 by georgesims        #+#    #+#             */
/*   Updated: 2023/11/22 16:01:10 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_data {
    void    *mlx;
    void	*win;
    void	*img;
}			t_data;

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

void    draw_map(char **map)
{
    
}

int main()
{
    const char  *filepath = "./map2.ber";
    t_data      data;
    char        **map;
    
    
    
    return(res);
}