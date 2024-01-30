/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:29:55 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/30 15:04:14 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Find index of cheapest node in Stack A
t_lst	*ft_find_cheapest(t_var *v)
{
	t_lst	*curr_a;
	t_lst	*find;
	int		min;

	if (v->stack_a->next == NULL)
		return (v->stack_a);
	curr_a = v->stack_a;
	min = *(curr_a->cost);
	while (curr_a != NULL)
	{
		if (*(curr_a->cost) < min)
			min = *(curr_a->cost);
		curr_a = curr_a->next;
	}
	find = v->stack_a;
	while (find != NULL)
	{
		if (*(find->cost) == min)
			break ;
		find = find->next;
	}
	return (find);
}

// Runs operations for the situation when the cheapest number
// is in the first half of A
// This function can definitely be merged with 
// First_half_A_second_half_B (just like the other one)
int	ft_operator_first_half(t_var *v, t_lst *cheap, int rr, int ra)
{
	int	operations;
	int	steps_b;

	operations = 0;
	steps_b = ft_get_steps_brut(*(cheap->content), v->stack_b);
	if (steps_b > v->size_b / 2)
		steps_b = v->size_b - steps_b - rr;
	while (rr-- > 0)
		operations += ft_rr(v);
	while (ra-- > 0)
		operations += ft_ra(v);
	while (steps_b-- > 0)
		operations += ft_rb(v);
	operations += ft_pa(v);
	return (operations);
}

// Function to bring the largest number in stack B back to the top
void	ft_back_to_top(t_var *v)
{
	int		max;
	int		steps;
	t_lst	*curr_b;

	max = get_max(v->stack_b);
	curr_b = v->stack_b;
	steps = 0;
	while (curr_b && *(curr_b->content) != max)
	{
		steps++;
		curr_b = curr_b->next;
	}
	if (steps < v->size_b / 2)
	{
		while (steps-- > 0)
			v->operations += ft_rb(v);
	}
	else
	{
		while (steps++ < v->size_b)
			v->operations += ft_rrb(v);
	}
}
