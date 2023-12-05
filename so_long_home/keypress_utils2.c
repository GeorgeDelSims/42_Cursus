/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:28:04 by georgesims        #+#    #+#             */
/*   Updated: 2023/12/05 13:28:42 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int move_down(size_t row, size_t col, t_data *data)
{
    if (pos_conditions(row + 1, col, data) == 1)
    {
        data->map[row][col] = '0';
        data->map[row + 1][col] = 'P';
        data->count++;
        return (1);
    }
    return (0);
}

int move_up(size_t row, size_t col, t_data *data)
{
    if (pos_conditions(row - 1, col, data) == 1)
    {
        data->map[row][col] = '0';
        data->map[row - 1][col] = 'P';
        return (1);
    }
    return (0);
}

int move_left(size_t row, size_t col, t_data *data)
{
    if (pos_conditions(row, col - 1, data) == 1)
    {
        data->map[row][col] = '0';
        data->map[row][col - 1] = 'P';
        return (1);
    }
    return (0);
}

int move_right(size_t row, size_t col, t_data *data)
{
    if (pos_conditions(row, col + 1, data) == 1)
    {
        data->map[row][col] = '0';
        data->map[row][col + 1] = 'P';
        return (1);
    }
    return (0);
}

int escape(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
    return (0);
}