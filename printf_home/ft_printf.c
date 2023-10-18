/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:00:37 by gsims             #+#    #+#             */
/*   Updated: 2023/10/18 17:39:52 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

// Defines whether character is a cspdiux% case
int	ft_char(char c)
{
	char	*str;

	str = "cspdiuxX%";
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

// Printf function with variadic input
int	ft_printf(const char *s, ...)
{
	va_list	args;
	
	va_start(args, int);
	while (*s)
	{
		while (*s != '%')
		{
			ft_printchar(*s);
			s++;
		}
		if (*s == '%' && ft_char(*(s + 1)) == 1)
		{
			//Access format sorting function
		}
		s++;
	}
	

	va_end(args);
}
