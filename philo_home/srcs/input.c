/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:49:41 by gsims             #+#    #+#             */
/*   Updated: 2024/02/20 11:58:05 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

// Iterate over av[] and check that all values are numerical
static int	numeric_values_only(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// checks for correct number of args + check input format
int	input_check(int ac, char *av[])
{
	if (ac < 5 || ac > 6)
		return (0);
	if (!av)
		return (0);
	if (numeric_values_only(ac, av) == 0)
		return (0);
	if (ft_atoi(av[1]) > 200)
	{
		printf("Too many philosophers, ");
		return (0);
	}
	return (1);
}
