/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:00:37 by gsims             #+#    #+#             */
/*   Updated: 2023/10/24 11:25:52 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Defines whether character is a cspdiux% case
int	ft_char(char c)
{
	char	*s;

	s = "cspdiuxX%";
	while (*s)
	{
		if (c == *s)
			return (1);
		s++;
	}
	return (0);
}

int	ft_process_args(va_list args, const char format)
{
	if (format == 'c' || format == '%')
	{	
		ft_printchar(va_arg(args, int));
		return (1);
	}
	else if (format == 's')
		return (ft_printstr(va_arg(args, char *)));
	else if (format == 'p')
		return (ft_printptr(va_arg(args, unsigned long long)));
	else if (format == 'd' || format == 'i')
		return (ft_printint(va_arg(args, int)));
	else if (format == 'x')
		return (ft_printhex(va_arg(args, unsigned int)));
	else if (format == 'X')
		return (ft_printhexupper(va_arg(args, unsigned int)));
	else
		return (0);
}

// Printf function with variadic input
int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		charcount;

	i = 0;
	charcount = 0;
	va_start(args, s);
	while (s[i])
	{
		while (s[i] != '%')
		{
			ft_printchar(s[i]);
			i++;
			charcount++;
		}
		if (s[i] == '%' && ft_char(s[i + 1]) == 1)
		{
			charcount += ft_process_args(args, s[i]);
			i++;
		}
		i++;
	}
	va_end(args);
	return (charcount);
}
