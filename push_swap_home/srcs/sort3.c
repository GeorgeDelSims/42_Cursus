/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:47:00 by gsims             #+#    #+#             */
/*   Updated: 2024/01/30 15:04:32 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Operations for ft_sort_three
static void	ft_ops_stack_a(t_var *v, int rra, int ra, int rs)
{
	while (rra-- > 0)
	{
		v->operations += ft_rev_rotate(&v->stack_a);
		ft_printf("rra\n");
	}
	while (ra-- > 0)
	{
		v->operations += ft_rotate(&v->stack_a);
		ft_printf("ra\n");
	}
	while (rs-- > 0)
	{
		v->operations += ft_swap(&v->stack_a);
		ft_printf("sa\n");
	}
}

// Sorting algo for less than 5 numbers
void	ft_sort_three(t_var *v)
{
	t_lst	*curr_a;

	curr_a = v->stack_a;
	if (*(curr_a->content) == v->max_a)
	{
		if (*(curr_a->next->content) > v->min_a)
			ft_ops_stack_a(v, 2, 0, 1);
		else
			ft_ops_stack_a(v, 2, 0, 0);
	}
	else if (*(curr_a->next->content) == v->max_a)
	{
		if (*(curr_a->content) > v->min_a)
			ft_ops_stack_a(v, 1, 0, 0);
		else
			ft_ops_stack_a(v, 1, 0, 1);
	}
	else
	{
		if (*(curr_a->content) > v->min_a)
			ft_ops_stack_a(v, 0, 0, 1);
		else
			v->operations += 0;
	}
}

// Rotate A in order to have the minimum on top
static void	rotate_to_min(t_var *v)
{
	t_lst	*curr_a;
	int		steps;

	curr_a = v->stack_a;
	steps = 0;
	while (curr_a)
	{
		steps++;
		if (*(curr_a->content) == v->min_a)
			break ;
		curr_a = curr_a->next;
	}
	if (steps > v->size_a / 2)
	{
		while (steps++ <= v->size_a)
			ft_ops_stack_a(v, 1, 0, 0);
	}
	else
	{
		while (steps-- > 1)
			ft_ops_stack_a(v, 0, 1, 0);
	}
}

// Sorts fiver numbers or less. Finds min number in A, pushes to B.
// finds new min in A, pushes to B
// sorts a with the sort_three algo
// pushes both elements of B back to A
void	ft_sort_five(t_var *v)
{
	rotate_to_min(v);
	v->operations += ft_pa(v);
	refresh_min_max_a(v);
	rotate_to_min(v);
	v->operations += ft_pa(v);
	refresh_min_max_a(v);
	ft_sort_three(v);
	v->operations += ft_pb(v);
	v->operations += ft_pb_last(v);
}

// Junction function to go to sort 3 or sort 5
void	ft_sort_small(t_var *v)
{
	if (v->size_a < 4)
		ft_sort_three(v);
	else
		ft_sort_five(v);
}
