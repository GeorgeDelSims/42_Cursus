/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:14 by gsims             #+#    #+#             */
/*   Updated: 2024/01/11 15:03:17 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// receive a list of chars and spaces, check the validity of the input
// Initialise linked list A and turn all received chars into ints and put into linked list 
// initialise linked list B 
// implement each operation with a function
// print list of operations done
// Find some way of making the program choose which operation is the most effective? 

void	ft_input_check(int ac, char *av[])
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				write(1, "Error\n", 6);
				exit(1);
			}
		j++;
		}
	i++;
	}
}

// Initiate Stack A
t_list	*ft_init_a(int ac, char *av[])
{
	int		i;
	t_list	*stack_a;
	t_list	*new_node;
	int		*value;
	
	i = 1;
	stack_a = NULL;
	while (i < ac)
	{
		value = (int *)malloc(sizeof(int));
		*value = ft_atoi(av[i]);
		if (value == NULL)
			return (NULL);
		new_node = ft_lstnew(value);
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	return (stack_a);
}


// Print node function for debugging (to be used with ft_lstiter)
void print_node(void *content)
{
    printf("%d\n", *(int *)content);
}

// print for debugging purposes:
void	ft_print_stacks(t_list *stack_a, t_list *stack_b)
{
	ft_printf("stack A :\n");
	ft_lstiter(stack_a, print_node);
	ft_printf("stack B :\n");
	ft_lstiter(stack_b, print_node);
	ft_lstiter(stack_a, free);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	// int		size;`
	
	// check validity
	ft_input_check(ac, av);
	// Make linked list A 
	stack_a = ft_init_a(ac, av);
	stack_b = NULL;
	// ft_push(&stack_a, &stack_b);
	// ft_swap(&stack_a);
	ft_rotate(&stack_a);
	// size = ft_lstsize(stack_a);
	ft_print_stacks(stack_a, stack_b);	
	return (0);
}