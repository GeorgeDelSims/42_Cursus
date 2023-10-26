/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:20:16 by gsims             #+#    #+#             */
/*   Updated: 2023/10/26 18:02:57 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//strchr function
char	*ft_strchr(const char *s, int c)
{
	char	uc;
	int		i;

	uc = (char)c;
	if (uc == '\0')
	{
		i = ft_strlen(s);
		return ((char *)&s[i]);
	}
	else
	{
		i = 0;
		while (s[i] != '\0')
		{
			if (s[i] == uc)
				return ((char *)&s[i]);
			i++;
		}
		return (NULL);
	}
}

//Stringlcat function
size_t	ft_strlcat(char *restrict	dst, const char	*src, size_t	dstsize)
{
	size_t	i;
	size_t	j;
	size_t	srcsize;
	size_t	d_size;

	i = 0;
	srcsize = ft_strlen(src);
	d_size = ft_strlen(dst);
	if (dstsize > d_size)
	{
		while (dst[i] != '\0' && i < dstsize)
			i++;
		j = 0;
		while (src[j] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
		dst[i] = '\0';
		return (srcsize + d_size);
	}
	else
		return (srcsize + dstsize);
}

//Determines the length of a line 
int line_len(char *str)
{
    int i;
    
    i = 0;
    while (*str != '\n')
        i++;
    return (i);
}

// Frees the dynamically allocated buffers 
void    ft_free(char *buffer)
{
    while (*buffer != '\n')
    {
        free(*buffer);
        buffer++;
    }
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
char    *ft_line(char *buffer)
{
    char    *line;
    int     i;

    i = 0;
    line = (char *)malloc(line_len(buffer) + 1);
    if (line == NULL)
        return (NULL);
    while (buffer[i] && buffer[i] != '\n')
    {
        line[i] = buffer[i];
        i++;
    }
    ft_free(buffer);
    return (line);
}

//opens & reads from the text file (if read() has made it to the end of a file it returns 0)
char    *read_file(int fd, char **stash)
{
    int     read_len;
    char    *buffer;
    
    // Need a dynamically allocated buffer to store the characters from read()
    buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (buffer == NULL)
        return (NULL);
    //read() output is 0 at EOF and -1 in the case of an error
    read_len = 1;
    while (read_len > 0)
    {
        read_len = read(fd, buffer, BUFFER_SIZE);
        //need a function that concatenates buffer onto the stash array
        //check to see if there is a '\n' character in the buffer, in which case escape the loop
        if (ft_strchr(stash, 10) == 10)
            break ;
        //free the buffer 
    }
    if (read_len == -1)
        return (NULL);
    buffer[read_len] = '\0';
    return (stash);
}

//check for errors in input, imp
char    *get_next_line(int fd)
{
    static char **stash;
    char        *line;
    size_t      line_len;

    //read from file and save to static buffer:
    stash = read_file(fd, stash);
    
    //retrieve line from static buffer
    line = ft_line(stash);

    //re-initialise static buffer & save beginning of next line into static buffer
    stash = ft_next_line(stash);

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
