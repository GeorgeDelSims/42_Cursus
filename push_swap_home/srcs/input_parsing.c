/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:36:08 by gsims             #+#    #+#             */
/*   Updated: 2024/01/16 12:05:47 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_array(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

void	ft_num_input_check(int size, char *av[])
{
	int i;
	int j;
	
	i = 1;
	while (i < size)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				error(1, "Input incorrect");
		j++;
		}
	i++;
	}
}

int	ft_str_input_check(char *str)
{
	char	**array;
	int		size;
	int		i;
	
	array = ft_split(str, ' ');
	if (!array)
		error(1, "Input incorrect");
	size = ft_count_array(array);
	ft_num_input_check(size, array);
	i = 0;
	while (i < size)
	{
		ft_printf("array[%d] : %s\n", i, array[i]);
		i++;
	}
	return (size);
}

int	ft_input_check(int ac, char *av[])
{
	int	size;
	
	if (ac == 2)
	{
		size = ft_str_input_check(av[1]);
		return (size);
	}
	else
	{
		ft_num_input_check(ac, av);
		return (ac);
	}
}