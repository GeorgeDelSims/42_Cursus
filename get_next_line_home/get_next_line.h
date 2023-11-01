/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:20:13 by gsims             #+#    #+#             */
/*   Updated: 2023/11/01 11:23:55 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#endif

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE (8)

int	    ft_strlen(const char *s);
int     line_len(char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
size_t	ft_strlcpy(char	*dst, const char	*src, size_t	dstsize);
char	*ft_strchr(const char *s, int c);
char    *get_next_line(int fd);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char    *ft_extract_line(char **stash, int mod);
char    *read_file(int fd, char *stash, int *p_mod);
char    *get_next_line(int fd);

#endif
