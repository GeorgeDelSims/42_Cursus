/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:19:31 by gsims             #+#    #+#             */
/*   Updated: 2024/01/31 13:19:46 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

// Checker gets given the same list of chars 
// turns them into a linked list just like push_swap 
// calls push swap to get the commands for sorting
// reads the commands from STDOUT line by line 
// applies the commands to the linked list
// Checks the list is sorted 
// Returns OK, KO or Error depending on the result 


// Initiate variables and check input
void	ft_init_var_check(t_var *vc, int ac, char *av[])
{
	int		size_a;
	
	vc->args = ft_input_check(ac, av);
	size_a = ft_count_array(vc->args);
	vc->size_a = ft_init_a(vc, size_a, ac, vc->args);
	// refresh_min_max_a(vc);
	ft_print_stacks(vc->stack_a, vc->stack_b);
}



int	main(int ac, char *av[])
{
	t_var	*vc;

	vc = (t_var *)malloc(sizeof(t_var *));
	if (!vc)
		ft_error(1, "vc malloc failed\n");
	ft_init_var_check(vc, ac, av);
	ft_printf("checker checked\n");
	return (0);
}