/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 10:06:39 by gsims             #+#    #+#             */
/*   Updated: 2024/01/23 16:42:30 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_ra(t_var *v)
{
	int	res;

	res = ft_rotate(&v->stack_a);
	ft_printf("ra\n");
	ft_fill_values(v);
	return (res);
}

int	ft_rb(t_var *v)
{
	int	res;

	res = ft_rotate(&v->stack_b);
	ft_printf("rb\n");
	ft_fill_values(v);
	return (res);
}

int	ft_rr(t_var *v)
{
	ft_rotate(&v->stack_a);
	ft_rotate(&v->stack_b);
	ft_printf("rr\n");
	ft_fill_values(v);
	return (1);
}

int	ft_rra(t_var *v)
{
	int	res;

	res = ft_rev_rotate(&v->stack_a);
	ft_printf("rra\n");
	ft_fill_values(v);
	return (res);
}

int	ft_rrb(t_var *v)
{
	int	res;

	res = ft_rev_rotate(&v->stack_b);
	ft_printf("rrb\n");
	ft_fill_values(v);
	return (res);
}
