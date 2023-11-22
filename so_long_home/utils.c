/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:56:30 by georgesims        #+#    #+#             */
/*   Updated: 2023/11/22 14:42:23 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Get width and height in order to malloc a char** for the map 

size_t	get_width(char *filepath)
{
    int		fd;
    int		bytesread;
    size_t	width;
    char	buffer[BUFFER_SIZE];
    char	*newline_pos;

    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (0);
    width = 0;
    while ((bytesread = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        if (bytesread <= 0)
            return (0);
        newline_pos = ft_strchr(buffer, '\n');
		if (newline_pos)
        {
            width += newline_pos - buffer;
            break ;
        }
        else
            width += bytesread;
	}
    close(fd);
    return (width);
}