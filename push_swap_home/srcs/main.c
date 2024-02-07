/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:14 by gsims             #+#    #+#             */
/*   Updated: 2024/02/07 11:38:52 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
// ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
// Initiate Stack A
int	ft_init_a(t_var *v, int size_a, int ac, char *av[])
{
	int		i;
	int		res;
	t_lst	*new_node;
	int		*value;

	if (size_a > 2 && size_a == ac)
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

	v->args = ft_input_check(v, ac, av);
	size_a = ft_count_array(v->args);
	v->size_a = ft_init_a(v, size_a, ac, v->args);
	v->stack_b = NULL;
	refresh_min_max_a(v);
	v->operations = 0;
	if (v->size_a < 6)
	{
		ft_sort_small(v);
		ft_free_stacks(v);
		exit(0);
	}
	v->operations += ft_pa(v);
	v->operations += ft_pa(v);
	if (*(v->stack_b->content) < *(v->stack_b->next->content))
		v->operations += ft_sb(v);
}

int	main(int ac, char *av[])
{
	t_var	*v;

	v = (t_var *)malloc(sizeof(t_var));
	if (!v)
		ft_error(1, "variable memory not allocated\n");
	ft_init_var(v, ac, av);
	ft_sort(v);
	if (v->quotes == 1)
		ft_free_array(v->args);
	ft_free_stacks(v);
	return (0);
}
