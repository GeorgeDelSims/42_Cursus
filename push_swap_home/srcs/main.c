/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:14 by gsims             #+#    #+#             */
/*   Updated: 2024/01/16 12:14:04 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// receive a list of chars and spaces, check the validity of the input
// Initialise linked list A and turn all received chars into ints and put into linked list 
// initialise linked list B 
// implement each operation with a function
// print list of operations done
// Find some way of making the program choose which operation is the most effective? 

// Initiate Stack A
void	ft_init_a(t_var *v, int size, int ac, char *av[])
{
	int		i;
	t_lst	*new_node;
	int		*value;
	
	if (size == ac)
		i = 1;
	else
	{
		i = 0;
	}
	v->stack_a = NULL;
	while (i < size)
	{
		value = (int *)malloc(sizeof(int));
		if (value == NULL)
			error(1, "value memory not allocated\n");
		*value = ft_atoi(av[i]);
		new_node = ft_lst_new(value);
		ft_lst_add_back(&v->stack_a, new_node);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_var	*v;
	int		size;
	
	size = ft_input_check(ac, av);
	ft_printf("size after input check : %d\n", size);
	v = (t_var *)malloc(sizeof(t_var *) + 1);
	if (!v)
		error(1, "variable memory not allocated\n");
	ft_printf("size = %d\n ac = %d\n", size, ac);
	ft_init_a(v, size, ac, av);
	v->stack_b = NULL;
	// ft_push(&stack_a, &stack_b);
	// ft_swap(&stack_a);
	// size = ft_lstsize(stack_a);
	ft_print_stacks(v->stack_a, v->stack_b);	
	return (0);
}