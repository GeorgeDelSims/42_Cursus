/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:00:37 by gsims             #+#    #+#             */
/*   Updated: 2023/10/24 15:04:17 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Defines whether character is a cspdiuxX% case
int	ft_char(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'u' || c == 'x'	|| c == 'X')
		return (1);
	else
		return (0);
}

int	ft_printchar_normal(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_process_args(va_list args, const char format)
{
	int	charcount;

	charcount = 0;
	if (format == 'c' || format == '%')
	{	
		ft_printchar(va_arg(args, int));
		charcount += 1;
	}
	else if (format == 's')
		charcount += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		charcount += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		charcount += ft_printint(va_arg(args, int));
	else if (format == 'x')
		charcount += ft_printhex(va_arg(args, unsigned int));
	else if (format == 'X')
		charcount += ft_printhexupper(va_arg(args, unsigned int));
	else if (format == 'u')
		charcount += ft_printunsigned(va_arg(args, unsigned int));
	return (charcount);
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
		if (s[i] == '%')
		{
			if (s[i + 1] == '%')
				charcount += ft_printchar_normal('%');
			else if (ft_char(s[i + 1]) == 1)
				charcount += ft_process_args(args, s[i + 1]);
			i++;
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (charcount);
}
