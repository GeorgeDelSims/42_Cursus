/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:57:10 by gsims             #+#    #+#             */
/*   Updated: 2023/10/12 12:31:22 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char	*str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == 9 || *str == 32)
		str++;
	if (ft_isdigit(*str) == 0)
	{
		if (*str != '-' && *str != '+' && ft_isdigit(*(str + 1)) == 0)
			return (0);
		else
			if (*str == '-')
				sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
/*
int	main()
{
	const char	*str = "-432";

	printf("result : %d\n", ft_atoi(str));
	return (0);
}*/
