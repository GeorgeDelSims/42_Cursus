/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:58:21 by gsims             #+#    #+#             */
/*   Updated: 2023/11/21 10:46:18 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <mlx.h>


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

int main()
{
	char	*relative_path = "./textures/KingKong.xpm";
	t_data	data;	
	
	// initialise window 
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 1080, 1080 , "so_long");
	
	// Create image and associate it to window
	data.img = mlx_new_image(data.mlx, 1080, 1080);
	data.img = mlx_xpm_file_to_image(data.mlx, relative_path, &data.x, &data.y);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_len, &data.endian);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	
	// start event loop
	mlx_loop(data.mlx);
	return (0);
}