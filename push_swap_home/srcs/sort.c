/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:20:09 by gsims             #+#    #+#             */
/*   Updated: 2024/01/30 15:03:46 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// Runs operations for the situation when the cheapest number
// is in the second half of A
static int	ft_operator_second_half(t_var *v, t_lst *cheap, int rrr, int rra)
{
	int	operations;
	int	steps_b;

	operations = 0;
	steps_b = ft_get_steps_brut(*(cheap->content), v->stack_b);
	while (rrr-- > 0)
		operations += ft_rrr(v);
	while (rra-- > 0)
		operations += ft_rra(v);
	if (steps_b > v->size_b / 2)
	{
		steps_b = v->size_b - steps_b;
		while (steps_b-- > 0)
			operations += ft_rrb(v);
	}
	else
	{
		while (steps_b-- > 0)
			operations += ft_rb(v);
	}
	operations += ft_pa(v);
	return (operations);
}

// Runs operations for the situation when the cheapest number is in the first
// half of A and needs to go in the second half of B
static int	ft_operator_first_half_a_second_half_b(t_var *v, int ra, int rrb)
{
	int	operations;

	operations = 0;
	while (ra-- > 0)
		operations += ft_ra(v);
	while (rrb-- > 0)
		operations += ft_rrb(v);
	operations += ft_pa(v);
	return (operations);
}

// Sorts cheapest value if it is in the first half of Stack A
// Function checks if the value should go in first or second half of Stack B
// Checks if there are double operations to be made
static void	sort_first_half(t_var *v, t_sort *s, t_lst *cheap)
{
	int	rr;
	int	ra;
	int	rrb;

	if (s->idx_b <= v->size_b / 2)
	{
		if (s->cost <= s->idx + 1)
		{
			ra = s->idx - s->double_ops;
			rr = s->double_ops;
			v->operations += ft_operator_first_half(v, cheap, rr, ra);
		}
		else
		{
			ra = s->idx;
			v->operations += ft_operator_first_half(v, cheap, 0, ra);
		}
	}
	else
	{
		ra = s->idx;
		rrb = v->size_b - s->idx_b;
		v->operations += ft_operator_first_half_a_second_half_b(v, ra, rrb);
	}
}

// Sorts cheapest value if it is in the second half of Stack A
// Function checks if the value should go in first or second half of Stack B
// Checks if there are double operations to be made
static void	sort_second_half(t_var *v, t_sort *s, t_lst *cheap)
{
	int	rrr;
	int	rra;

	if (s->cost < v->size_a - s->idx)
	{
		rrr = (v->size_a - s->idx) - s->cost;
		rra = v->size_a - s->idx;
		v->operations += ft_operator_second_half(v, cheap, rrr, rra);
	}
	else
	{
		rra = v->size_a - s->idx;
		v->operations += ft_operator_second_half(v, cheap, 0, rra);
	}
}

// actually sort the nodes by using the operation functions
void	ft_sort(t_var *v)
{
	t_lst	*cheap;
	t_lst	*curr_b;
	t_sort	*s;

	s = (t_sort *)malloc(sizeof(t_sort *));
	if (!s)
		ft_error(1, "malloc error for struct t_sort");
	while (v->size_a > 0)
	{
		curr_b = v->stack_b;
		cheap = ft_find_cheapest(v);
		s->idx = *(cheap->idx);
		s->cost = *(cheap->cost);
		s->idx_b = ft_get_steps_brut(*(cheap->content), curr_b);
		s->double_ops = 1 + s->idx - s->cost;
		if (s->idx <= v->size_a / 2)
			sort_first_half(v, s, cheap);
		else
			sort_second_half(v, s, cheap);
	}
	ft_back_to_top(v);
	while (v->size_b > 1)
		v->operations += ft_pb(v);
	v->operations += ft_pb_last(v);
}
