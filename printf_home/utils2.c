/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:06:57 by gsims             #+#    #+#             */
/*   Updated: 2023/10/24 17:51:20 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printchar_hexupper(unsigned int num)
{
	char	c;

	if (num < 10)
		ft_printchar_rec((int)num);
	else if (num > 9)
	{
		c = num - 10 + 'A';
		write(1, &c, 1);
	}	
}

int	ft_printhexupper(unsigned int num)
{
	int	res;

	res = ft_countint((int)num);
	ft_puthexupper(num);
	return (res);
}

void	ft_puthexupper(unsigned int num)
{
	if (num < 0)
		return ;
	if (num <= 16)
		ft_printchar_hexupper(num);
	if (num > 16)
	{
		ft_puthexupper(num / 16);
		ft_puthexupper(num % 16);
	}
}

void	ft_printchar_hex(unsigned int num)
{
	unsigned char	c;

	if (num <= 9)
		ft_printchar_rec((unsigned int)num);
	else if (num > 9)
	{
		c = num - 10 + 'a';
		write(1, &c, 1);
	}	
}

int	ft_printhex(unsigned int num)
{
	int	res;

	res = ft_countint_hex((int)num);
	ft_puthex(num);
	return (res);
}
