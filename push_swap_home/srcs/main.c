/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:14 by gsims             #+#    #+#             */
/*   Updated: 2024/01/26 09:43:20 by georgesims       ###   ########.fr       */
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
	v->operations = ft_pa_start(v);
	v->operations += ft_pa(v);
	ft_printf("BEGINNING\n");
	if (*(v->stack_b->content) < *(v->stack_b->next->content))
		v->operations += ft_sb(v);
	ft_print_stacks(v->stack_a, v->stack_b);
}

int	main(int ac, char *av[])
{
	t_var	*v;
		
	v = (t_var *)malloc(sizeof(t_var));
	if (!v)
		ft_error(1, "variable memory not allocated\n");
	ft_init_var(v, ac, av);
	ft_sort(v);
	ft_print_stacks(v->stack_a, v->stack_b);
	ft_printf("operations : %d\n", v->operations);
	ft_free_stacks(v);
	return (0);
}
