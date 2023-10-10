/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:57:10 by gsims             #+#    #+#             */
/*   Updated: 2023/10/10 08:57:27 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char	*str)
{
	int		result;
	int		counter;

	result = 0;
	counter = 0;
	while (*str <= 32)
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			counter++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (counter % 2 == 1)
		result *= -1;
	return (result);
}
