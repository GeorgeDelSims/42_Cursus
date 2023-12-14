/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:22:56 by gsims             #+#    #+#             */
/*   Updated: 2023/12/14 11:19:07 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_edges(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		if (data->map[i][j] != '1')
			return (0);
		while (data->map[i][j])
		{
			if ((i == 0 || i == (int)data->map_height - 1)
				&& data->map[i][j] != '1')
				return (0);
			j++;
		}
		if (data->map[i][data->map_width - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// Prints the map for debugging
void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			ft_printf("%c ", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}
