/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:20:16 by gsims             #+#    #+#             */
/*   Updated: 2023/10/26 14:37:49 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Determines the size of a line 
int line_len(char *str)
{
    int i;
    
    i = 0;
    while (*str != '\n')
        i++;
    return (i);
}

// Frees the dynamically allocated buffers 
void    ft_free()
{
    
}

//moves the buffer pointer to the end of the "current" line (effectively deleting the current line in the dynamic buffer)
//
char    *ft_next_line(char *buffer)
{
    int i;
    int j;
    
    i = 0;
    while (buffer[i] && buffer[i] != '\n')
        i++;        
    j = 0;
    while (buffer[j] && buffer[i])
    {
        buffer[j] = buffer[i + j];
        j++;
    }
    buffer[i + j] = '\0';
    return (buffer);
}

//retrieves the current line from the buffer 
char    *ft_line(char *dyn_buffer)
{
    char    *line;
    int     i;

    i = 0;
    line = (char *)malloc(line_len(dyn_buffer) + 1);
    if (line == NULL)
        return (NULL);
    while (dyn_buffer[i] && dyn_buffer[i] != '\n')
    {
        line[i] = dyn_buffer[i];
        i++;
    }
    return (line);
}

//opens & reads from the text file (if read() has made it to the end of a file it returns 0)
char    *read_file(int fd, char *dyn_buffer)
{
    size_t  read_len;

    dyn_buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (dyn_buffer == NULL)
        return (NULL);
    read_len = read(fd, dyn_buffer, BUFFER_SIZE);
    dyn_buffer[read_len] = '\0';
    return (dyn_buffer);
}

//check for errors in input, imp
char    *get_next_line(int fd)
{
    static char buffer;
    char        *line;
    size_t      line_len;

    //read from file and save to static buffer:
    buffer = read_file(fd, buffer);
    
    //retrieve line from static buffer
    line = ft_line(buffer);

    //re-initialise static buffer & save beginning of next line into static buffer
    buffer = ft_next_line(buffer);

    //return line
    return (line);
}

//Main test function
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        write(1, "More arguments needed\0", 22);
        return (NULL);
    }
    else 
    {
        
    }
}
