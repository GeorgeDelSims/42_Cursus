/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:30:06 by gsims             #+#    #+#             */
/*   Updated: 2023/12/04 13:14:10 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_image {
    void    *img;
    int     col;
    int     row;
}			t_image;

typedef struct s_data {
    void    *mlx;
    void	*win;
    int     pixel_rate;
    char    **map;
	size_t	map_height;
	size_t	map_width;
    t_image wall;
    t_image floor;
    t_image collectible;
    t_image exit;
    t_image player;
    t_image player_pos;
}			t_data;

void    get_dimensions(const char *filepath, size_t *x, size_t *y);
char    **read_map(const char *filepath, t_data *data);
void    draw_map(char **map, t_data *data);
void    init_images(t_data *data);

#endif