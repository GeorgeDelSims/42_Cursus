/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:22:50 by gsims             #+#    #+#             */
/*   Updated: 2023/10/10 19:17:58 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size(int n)
{
	int	size;

	size = 1;
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	size--;
	return (size);
}

char	*ft_itoa(int n)
{
	int			size;
	long int	num;
	char		*res;

	num = n;
	size = ft_get_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		size++;
		num *= -1;
	}
	res = (char *)malloc(size + 1);
	if (res == NULL)
		return (NULL);
	while (size--)
	{
		*(res + size) = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		*res = '-';
	else if (n == 0)
		*res = '0';
	return (res);
}
/*
int	main()
{
	int	n = -52405430;

	printf("%s\n", ft_itoa(n));
	return (0);
}*/
