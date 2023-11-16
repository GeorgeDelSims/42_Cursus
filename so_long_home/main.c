/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 09:31:12 by gsims             #+#    #+#             */
/*   Updated: 2023/11/16 15:57:27 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
	int		keycode;
}			t_data;

void draw_square(t_data *data)
{
	// Clear the window
	mlx_clear_window(data->mlx, data->win);
	
	// Draw four points of a square
	mlx_pixel_put(data->mlx, data->win, data->x, data->y, 0x00FF0000);
	mlx_pixel_put(data->mlx, data->win, data->x + 1, data->y, 0x00FF0000);
	mlx_pixel_put(data->mlx, data->win, data->x, data->y + 1, 0x00FF0000);
	mlx_pixel_put(data->mlx, data->win, data->x + 1, data->y + 1, 0x00FF0000);
}

int	ft_keypress(int keycode, t_data *data)
{
	if (data->keycode == 5)
		data->x -= 10;
	else if (data->keycode == 13)
		data->y += 10;
	else if (data->keycode == 1)
		data->y -= 10;
	else if (data->keycode == 2)
		data->x += 10;
	draw_square(data);
	return (0);
}

int	render_next_frame(void *data)
{
	if (data)
		return (0);
	//continuous rendering code
	return (0);
}

int main()
{
	t_data	data;
	
	// initialise window 
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1080, 1080 , "so_long");
	
	// Create image and associate it to window
	data.img = mlx_new_image(data.mlx, 1080, 1080);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_len, &data.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);

	//initial position of square 
	data.x = 100;
	data.y = 100;
	
	// set up key press callback
	mlx_key_hook(data.win, ft_keypress, &data);
	
	// look hook for continuous rendering
	mlx_loop_hook(data.mlx, render_next_frame, &data);
	
	// start event loop
	mlx_loop(data.mlx);
}