/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:30:06 by gsims             #+#    #+#             */
/*   Updated: 2023/12/12 13:41:15 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_image
{
	void	*img;
	int		col;
	int		row;
}			t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		pixel_rate;
	int		count;
	char	**map;
	size_t	map_height;
	size_t	map_width;
	t_image	wall;
	t_image	floor;
	t_image	collectible;
	t_image	exit;
	t_image	player;
	t_image	player_pos;
}			t_data;

typedef struct s_mc // Map check struct
{
	size_t		p;
	size_t		e;
	size_t		c;
	size_t		i;
	size_t		j;
}				t_mc;

void		get_dimensions(const char *filepath, size_t *x, size_t *y);
char		**read_map(const char *filepath, t_data *data);
void		draw_map(char **map, t_data *data);
void		init_images(t_data *data);
int			check_map(char **map);
void		init_images(t_data *data);
int			ft_free(void *ptr);
void		ft_free_map(char **map);
int			handle_close(t_data *data);
int			render_next_frame(void *data);
int			pos_conditions(size_t row, size_t col, t_data *data);
int			ft_keypress(int keycode, void *param);
int			move_down(size_t row, size_t col, t_data *data);
int			move_up(size_t row, size_t col, t_data *data);
int			move_left(size_t row, size_t col, t_data *data);
int			move_right(size_t row, size_t col, t_data *data);
int			escape(t_data *data);
int			check_path(t_data *data);
t_mc		*init_map_check(t_mc *mc);
void		print_map(char **map);
void		find_player_pos(t_data *data);

#endif