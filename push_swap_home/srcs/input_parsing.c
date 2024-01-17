/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:36:08 by gsims             #+#    #+#             */
/*   Updated: 2024/01/17 10:28:56 by gsims            ###   ########.fr       */
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

void	ft_num_input_check(int i, int size, char **args)
{
	int j;
	
	while (i < size)
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] < '0' || args[i][j] > '9')
				ft_error(1, "Input incorrect");
		j++;
		}
	i++;
	}
}

char	**ft_str_input_check(char *str)
{
	char	**args;
	int		size;
	
	args = ft_split(str, ' ');
	if (!args)
		ft_error(1, "Input incorrect");
	size = ft_count_array(args);
	ft_num_input_check(0, size, args);
	return (args);
}

char	**ft_input_check(int ac, char *av[])
{
	char	**args;
	
	if (ac < 2)
		ft_error(1, "No arguments given.");
	if (ac == 2)
	{
		args = ft_str_input_check(av[1]);
		return (args);
	}
	else
	{
		ft_num_input_check(1, ac, av);
		return (av);
	}
}
