/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:31:12 by gsims             #+#    #+#             */
/*   Updated: 2023/11/21 14:58:20 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	void	*map;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	int		keycode;
	char	*relative_path;

}			t_data;

char	**read_map(char filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (NULL);
}

void	ft_draw_map(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	

}

/*
void	ft_draw_img(t_data *data)
{
	mlx_clear_window(data->mlx, data->win);
	mlx_xpm_file_to_image(data->mlx, data->relative_path, data->x, data->y);
}

int ft_keypress(int keycode, t_data *data)
{
	if (keycode == 0) //keycode for a
		data->y -= 10;
	else if (keycode == 13) //keycode for w
		data->x += 10;
	else if (keycode == 1) //keycode for s
		data->x -= 10;
	else if (keycode == 2) //keycode for d
		data->y += 10;
	else if (keycode == 53) //keycode for ESC
		mlx_destroy_window(data->mlx, data->win);
	ft_draw_img(data);
	return (0);
}
*/
int	render_next_frame(void *data)
{
	if (data)
		return (0);
	mlx_do_sync(&data);
	//continuous rendering code
	return (0);
}

int main()
{
	t_data	data;
	
	data.relative_path = "./textures/KingKong.xpm";
	// initialise window 
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1024, 1024 , "so_long");
	
	// Create image and associate it to window
	data.img = mlx_new_image(data.mlx, 1024, 1024);
	data.map = mlx_new_image(data.mlx, 1024, 1024);

	//initial position of cursor 
	//data.x = 320;
	//data.y = 320;

	//Create image of King Kong
	data.img = mlx_xpm_file_to_image(data.mlx, data.relative_path, &data.x, &data.y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_len, &data.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img, data.x, data.y);

	// set up key press callback
	mlx_key_hook(data.win, ft_keypress, &data);
	
	// look hook for continuous rendering
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	
	// start event loop
	mlx_loop(data.mlx);
	return (0);
}