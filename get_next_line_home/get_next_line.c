/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:20:16 by gsims             #+#    #+#             */
/*   Updated: 2023/10/31 12:11:41 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//retrieves the current line from the string in the stash at index fd 
// replaces stash[fd] with the rest of the string (after the first newline)
char    *ft_extract_line(char *stash)
{
    char            *line;
    char            *temp;
    unsigned int    line_len;
    unsigned int    rest_len;

    line_len = 0;
    while (stash && stash[line_len] != '\n')
        line_len++;
    line = ft_substr(stash, 0, line_len);
    rest_len = line_len;
    while (stash[rest_len] != '\0')
        rest_len++;
    temp = ft_substr(stash, line_len, rest_len);
    free(stash);
    stash = temp;
    free(temp);
    return (line);
}

//opens & reads from the text file (if read() has made it to the end of a file it returns 0)
// function loops over the file and joins the content into stash (at index fd) until reaching a newline character, in which case it exits the loop. 
char    *read_file(int fd, char *stash)
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
        if (!stash)
            stash = "";
        temp = stash;
        stash = ft_strjoin(temp, buffer);
        free(temp);
        if (ft_strchr(buffer , 10))
            break ;
    }
    return (stash);
}

//check for errors in input, imp
char    *get_next_line(int fd)
{
    static char *stash;
    char        *line;

    //read from file and save to static buffer:
    stash = read_file(fd, stash);
    //retrieve line from static buffer
    line = ft_extract_line(stash);
    //return line
    return (line);
}

//Main test function
int main()
{
    int  fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error\n");
        return (0);   
    }
    line = get_next_line(fd);
    printf("%s\n", line);    
    return (0);
}
