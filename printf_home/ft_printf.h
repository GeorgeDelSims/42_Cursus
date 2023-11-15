/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:33:07 by gsims             #+#    #+#             */
/*   Updated: 2023/10/25 13:24:36 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_printchar(unsigned int num);
void	ft_printchar_rec(unsigned int num);
int		ft_putchar(int c);
int		ft_printstr(char *s);
int		ft_printint(int num);
int		ft_printunsigned(unsigned int num);
void	ft_putunsigned(unsigned int num);
int		ft_printhexa(unsigned int num, char c);
void	ft_printchar_hex(unsigned int num);
int		ft_printptr(unsigned long long num);
void	ft_putptr(unsigned long long num);
int		ft_char(char c);
int		ft_printf(const char *s, ...);
int		ft_countint(int num);
int		ft_countint_hex(unsigned long long num);

#endif
