/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:20:13 by gsims             #+#    #+#             */
/*   Updated: 2023/10/26 15:50:18 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE (128)

int     line_len(char *str)
char    *get_next_line(int fd)
void    ft_free(char *buffer)
char    *ft_line(char *dyn_buffer)
char    *ft_next_line(char *buffer)
char    *read_file(int fd, char *dyn_buffer)

#endif
