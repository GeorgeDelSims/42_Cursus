/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:14 by gsims             #+#    #+#             */
/*   Updated: 2024/02/05 08:51:11 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
// ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
// Initiate Stack A

int	main(int ac, char *av[])
{
	t_var	*v;

	v = (t_var *)malloc(sizeof(t_var));
	if (!v)
		ft_error(1, "variable memory not allocated\n");
	ft_init_var(v, ac, av);
	ft_sort(v);
	ft_free_stacks(v);
	return (0);
}
