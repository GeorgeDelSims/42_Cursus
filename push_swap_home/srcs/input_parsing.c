/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:36:08 by gsims             #+#    #+#             */
/*   Updated: 2024/01/25 13:38:07 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	ft_strdiff(char *s1, char *s2)
{
	int	i;
	
	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	else
		return (1);
}

static void	ft_check_dups(char **array, char *str, int index)
{
	int	k;
	
	if (!array)
		ft_error(1, "Input incorrect");
	k = 0;
	while (array[k])
	{
		if (k != index && ft_strdiff(array[k], str) == 0)
		{
			ft_printf("Duplicate numbers in input : %s\n", str);
			exit(1);
		}
		k++;
	}
}

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
			ft_check_dups(args, args[i], i);
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
