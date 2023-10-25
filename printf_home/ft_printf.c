/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 15:00:37 by gsims             #+#    #+#             */
/*   Updated: 2023/10/25 11:17:34 by gsims            ###   ########.fr       */
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

int	ft_process_args(va_list args, const char format)
{
	int	charcount;

	charcount = 0;
	if (format == 'c' || format == '%')
		charcount += ft_printchar(va_arg(args, int));
	else if (format == 's')
		charcount += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		charcount += ft_printptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		charcount += ft_printint(va_arg(args, int));
	else if (format == 'x')
		charcount += ft_printhexa(va_arg(args, unsigned int), 'x');
	else if (format == 'X')
		charcount += ft_printhexa(va_arg(args, unsigned int), 'X');
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
				charcount += ft_printchar(37);
			else if (ft_char(s[i + 1]) == 1)
				charcount += ft_process_args(args, s[i + 1]);
			i++;
		}
		else
			charcount += ft_printchar((int)s[i]);
		i++;
	}
	va_end(args);
	return (charcount);
}
