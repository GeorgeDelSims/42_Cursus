/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:36:08 by gsims             #+#    #+#             */
/*   Updated: 2024/02/12 11:38:37 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// Checks for input above MAXINT or below MININT 
static void	ft_int_max_min(char *str)
{
	if (ft_strlen(str) > 11)
		ft_error(1, "input number too long to fit in an INT");
	else if (ft_strlen(str) == 10)
	{
		ft_printf("strncmp : %d\n", ft_strncmp(str, "2147483647", 10));
		if (ft_strncmp(str, "2147483647", 10) > 0)
			ft_error(1, "input above MAXINT");
	}
	else if (ft_strlen(str) == 11)
	{
		if (ft_strncmp(str, "-2147483648", 11) > 0)
		{
			if (str[0] != '-')
				ft_error(1, "input above MAXINT 2");
			else
				ft_error(1, "input below MININT");
		}
	}
}


// Checks that all characters are number characters
static void	ft_num_input_check(int i, int size, char **args)
{
	int	j;

	while (i < size)
	{
		j = 0;
		while (args[i][j])
		{
			if ((args[i][j] < '0' || args[i][j] > '9') && args[i][j] != '-')
				ft_error(1, "Input incorrect");
			if (args[i][j] == '-' && (args[i][j + 1] < '0' || args[i][j
					+ 1] > '9' || !args[i][j + 1]))
				ft_error(1, "Input incorrect");
			ft_int_max_min(args[i]);
			j++;
		}
		i++;
	}
}

// Input check for the case in which the number array is given
// between brackets as a single large string
static char	**ft_str_input_check(char *str)
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

// Input check Main function
char	**ft_input_check(t_var *v, int ac, char *av[])
{
	char	**args;

	if (ac < 2)
		exit(0);
	if (ac == 2)
	{
		v->quotes = 1;
		args = ft_str_input_check(av[1]);
		return (args);
	}
	else
	{
		v->quotes = 0;
		ft_num_input_check(1, ac, av);
		args = av;
		return (args);
	}
}
