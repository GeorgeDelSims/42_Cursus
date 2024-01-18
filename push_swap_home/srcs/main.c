/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:14 by gsims             #+#    #+#             */
/*   Updated: 2024/01/18 14:44:45 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// receive a list of chars and spaces, check the validity of the input
// Initialise linked list A and turn all received chars into ints and put into linked list 
// initialise linked list B 
// implement each operation with a function
// print list of operations done
// Find some way of making the program choose which operation is the most effective? 

// Still to do: 
// - Make sure it accepts negative values 
// - make sure it doesn't accept twin values (pas de doublons)

// Initiate Stack A
int	ft_init_a(t_var *v, int size_a, int ac, char *av[])
{
	int		i;
	int		res;
	t_lst	*new_node;
	int		*value;
	
	if (size_a == ac)
		i = 1;
	else
		i = 0;
	res = size_a - i;
	v->stack_a = NULL;
	while (i < size_a)
	{
		value = (int *)malloc(sizeof(int));
		if (value == NULL)
			ft_error(1, "value memory not allocated\n");
		*value = ft_atoi(av[i]);
		new_node = ft_lst_new(value, NULL, NULL);
		ft_lst_add_back(&v->stack_a, new_node);
		i++;
	}
	return (res);
}

// Initiate variables and check input 
void	ft_init_var(t_var *v, int ac, char *av[])
{
	int	size_a;
	
	v->args = ft_input_check(ac, av);
	size_a = ft_count_array(v->args);
	v->size_a = ft_init_a(v, size_a, ac, v->args);
	v->stack_b = NULL;
	ft_fill_values(v);
	// ft_print_array(args);
	// ft_printf("size_a : %d\n", v->size_a);
}

int	main(int ac, char *av[])
{
	t_var	*v;
	// int		sorted;
	// int		result;
		
	v = (t_var *)malloc(sizeof(t_var));
	if (!v)
		ft_error(1, "variable memory not allocated\n");
	ft_init_var(v, ac, av);
	// result = 0;
	// result += ft_sa(v);
	// result = ft_pa(v);
	// result += ft_pa(v);
	// result += ft_pa(v);
	// result += ft_rrr(v);
	//result += ft_pb(v);
	//result += ft_rr(v);
	//result += ft_pa(v);
	//result = ft_sort(v);
	// sorted = check_sort(v->stack_a);
	// ft_printf("result : %d\n", result);
	// ft_printf("sorted : %d\n", sorted);
	ft_printf("size_a : %d\n", v->size_a);
	ft_printf("size_b : %d\n", v->size_b);
	ft_print_stacks(v->stack_a, v->stack_b);
	// ft_print_stacks_backup(v->stack_a, v->stack_b);
	ft_free_stacks(v);
	return (0);
}
