/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:20:16 by gsims             #+#    #+#             */
/*   Updated: 2023/10/25 16:32:32 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//function reads a line from file at given file descriptor
char    *get_next_line(int fd)
{
    static char *stash;
    int         buf;
    
    buf = BUFFER_SIZE;
    
    return ("getnextline");
}

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
