/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:20:16 by gsims             #+#    #+#             */
/*   Updated: 2023/10/31 16:50:56 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//retrieves the current line from the string in the stash at index fd 
// replaces stash[fd] with the rest of the string (after the first newline)
char    *ft_extract_line(char **stash)
{
    char            *line;
    char            *temp;
    unsigned int    line_len;
    unsigned int    rest_len;

    line_len = 0;
    printf("Bonjour\n");
    while (*stash && (*stash)[line_len] != '\n')
        line_len++;
    line = ft_substr(*stash, 0, line_len);
    rest_len = line_len;
    while ((*stash)[rest_len] != '\0')
        rest_len++;
    temp = ft_substr(*stash, line_len + 1, rest_len);
    *stash = temp;
    return (line);
}

//opens & reads from the text file (if read() has made it to the end of a file it returns 0)
// function loops over the file and joins the content into stash until reaching a newline character, in which case it exits the loop. 
char    *read_file(int fd, char *stash)
{
    int     read_line;
    char    buffer[BUFFER_SIZE + 1];
    
    buffer[BUFFER_SIZE] = '\0';
    read_line = 1;
    while (read_line != 0)
    {
        read_line = read(fd, buffer, BUFFER_SIZE);
        if (read_line == -1)
            return (NULL);
        buffer[BUFFER_SIZE] = '\0';
        stash = ft_strjoin(stash, buffer);
        if (ft_strchr(buffer , '\n'))
            break ;
    }
    if (read_file <= 0 || !stash || *stash == '\n')
    {
        free(stash);
        return (NULL);
    }
    return (stash);
}

//check for errors in input, imp
char    *get_next_line(int fd)
{
    static char *stash;
    char        *line;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
	    return (0);
    stash = read_file(fd, stash);
    if (!stash)
        return (NULL);
    line = ft_extract_line(&stash);
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
    while ((line = get_next_line(fd)))
    {   
        printf("is the segfault here ? \n");
        printf("%s\n", line);
    }
    /*line = get_next_line(fd);
    printf("end printf: %s\n", line);
    line = get_next_line(fd);
    printf("end printf 2:%s\n", line);
    line = get_next_line(fd);
    printf("end printf 3:%s\n", line);*/
    return (0);
}