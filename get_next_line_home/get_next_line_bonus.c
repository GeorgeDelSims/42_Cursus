/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:20:16 by gsims             #+#    #+#             */
/*   Updated: 2023/10/31 10:59:51 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


//retrieves the current line from the string in the stash at index fd 
// replaces stash[fd] with the rest of the string (after the first newline)
char    *ft_extract_line(int fd, char **stash)
{
    char    *line;
    char    *temp;
    int     line_len;
    int     ext_len;

    line_len = 0;
    while (stash[fd] && stash[fd][line_len] != '\n')
        line_len++;
    line = (char *)malloc(line_len + 1);
    if (line == NULL)
        return (NULL);
    line = ft_substr(stash[fd], 0, line_len);
    ext_len = line_len;
    while (stash[fd][ext_len] != '\0')
        ext_len++;
    temp = ft_substr(stash[fd], line_len, ext_len);
    free(stash[fd]);
    stash[fd] = temp;
    free(temp);
    return (line);
}

//opens & reads from the text file (if read() has made it to the end of a file it returns 0)
// function loops over the file and joins the content into stash (at index fd) until reaching a newline character, in which case it exits the loop. 
char    *read_file(int fd, char **stash)
{
    int     read_line;
    char    *temp;
    char    buffer[BUFFER_SIZE];
    
    read_line = 1;
    while (read_line != 0)
    {
        read_line = read(fd, buffer, BUFFER_SIZE);
        if (read_line == -1)
            return (NULL);
        if (!(stash[fd]))
            stash[fd] = "";
        temp = stash[fd];
        stash[fd] = ft_strjoin(temp, buffer);
        free(temp);
        if (ft_strchr(buffer , '\n'))
            break ;
    }
    return (stash[fd]);
}

//check for errors in input, imp
char    *get_next_line(int fd)
{
    static char **stash;
    char        *line;
    size_t      line_len;

    //read from file and save to static buffer:
    stash[fd] = read_file(fd, buffer, stash);
    //retrieve line from static buffer
    line = ft_line(fd, stash[fd]);
    //return line
    return (line);
}

//Main test function
int main()
{
   
   return (0);
}
