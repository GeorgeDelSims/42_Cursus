/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 09:40:25 by gsims             #+#    #+#             */
/*   Updated: 2023/10/24 16:22:17 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int num)
{
	char	c;

	c = (char)num;
	write(1, &c, 1);
	return (1);
}

void	ft_printchar_rec(int num)
{
	char	c;

	c = (char)num;
	write(1, &c, 1);
}

int	ft_printstr(char	*s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_printint(int num)
{
	char	*str;

	str = ft_itoa(num);
//	printf("%s", str);
	ft_printstr(str);
	return (ft_countint(num));
}

int	ft_printunsigned(unsigned int num)
{
	int	i;

	i = ft_countint((int)num);
	ft_putunsigned(num);
	return (i);
}

void	ft_putunsigned(unsigned int num)
{
	if (num < 0)
		return ;
	if (num < 10)
		ft_printchar_rec(num + 48);
	if (num > 9)
	{
		ft_putunsigned(num / 10);
		ft_putunsigned(num % 10);
	}
}

/*
int	main()
{
	char			*str = "Hello";
	int				numint = -6742;
	int				num = 99999999;
	unsigned int	*ptr;

	ptr = &num;
	printf("printstr test :\n");
   	ft_printstr(str);
	printf("\nprintint test :\n");
	ft_printint(numint);
	printf("\nprintunsigned test :\n");
	ft_printunsigned(num);
	printf("\nprinthex test :\n");
	ft_printhex(num);
	printf("\nprinthexupper test :\n");
	ft_printhexupper(num);
	printf("\ncountint test :%d\n", ft_countint(num));
	ft_printptr((unsigned long long)ptr);
	printf("\n");
	return (0);
	}*/
