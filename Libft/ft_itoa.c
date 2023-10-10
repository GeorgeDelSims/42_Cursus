/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:22:50 by gsims             #+#    #+#             */
/*   Updated: 2023/10/10 18:37:56 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_get_size(int n)
{
	int	size;

	size = 1;
	while (n /= 10)
		size++;
	return (size);
}

char	*ft_itoa(int n)
{
	int		size;
	int		i;
	int		sign;
	char	*res;

	sign = 0;
	size = ft_get_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		size++;
		n *= -1;
		sign = 1;
	}
	res = (char *)malloc(size + 1);
	if (res == NULL)
		return NULL;
	if (n == 0)
		res[0] = '0';
	i = 0;
	while (n /= 10)
		res[i++] = (n % 10) + '0';
	printf("%d\n", n);
	return (res);
}

int	main()
{
	int	n = 67550;

	printf("%s\n", ft_itoa(n));
	return (0);
}
