/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 09:46:52 by gsims             #+#    #+#             */
/*   Updated: 2023/10/24 17:56:12 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countint(int num)
{
	int	i;

	i = 1;
	if (num < 0)
	{
		i++;
		num *= -1;
	}
	while (num > 9)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_countint_hex(unsigned long long num)
{
	int	i;

	i = 1;
	while (num >= 16)
	{
		num /= 16;
		i++;
	}
	return (i);
}

void	ft_puthex(unsigned int num)
{
	if (num < 0)
		return ;
	if (num < 16)
		ft_printchar_hex(num);
	if (num >= 16)
	{
		ft_puthex(num / 16);
		ft_puthex(num % 16);
	}
}

int	ft_printptr(unsigned long long num)
{
	int	res;
	
	res = write(1, "0x", 2);
	res += ft_countint_hex((unsigned long long)num);
	ft_putptr(num);
	return (res);
}

void	ft_putptr(unsigned long long num)
{
	if (num < 16)
		ft_printchar_hex((unsigned int)num);
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
}

/*
int	main()
{
	unsigned int	num = 31;

	printf("countint_hex test: %d\n", ft_countint_hex(num));
	printf("printchar_hex test\n");	
	ft_printchar_hex(num);
	write(1, "\n", 1);
	printf("printchar test:\n");
	ft_printchar(5);
	write(1, "\n", 1);
	printf("puthex test:\n");
	ft_puthex(num);
	printf("\n");
	return (0);
}*/
