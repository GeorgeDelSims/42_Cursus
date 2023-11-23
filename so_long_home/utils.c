/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:56:30 by georgesims        #+#    #+#             */
/*   Updated: 2023/11/23 09:55:25 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Get width in order to malloc a char** for the map 
size_t	get_width(int fd)
{
    int		bytesread;
    size_t	width;
    char	buffer[BUFFER_SIZE];
    char	*newline_pos;

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
    return (width);
}

// Count the number of characters in a buffer
static size_t	ft_countchar_buff(char *str, char c)
{
	size_t	count;
	int		i;
	
	i = 0;
	count = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

// Get height in order to malloc a char** for the map
size_t	get_height(int fd)
{
	int		bytesread;
	size_t	height;
	char	buffer[BUFFER_SIZE];
	
	height = 0;
	while ((bytesread = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		if (bytesread <= 0)
			return (0);
		height += ft_countchar_buff(buffer, '\n');
	}
	return (height);
}