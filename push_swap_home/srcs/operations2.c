/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:42:59 by gsims             #+#    #+#             */
/*   Updated: 2024/01/30 16:25:59 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sb(t_var *v)
{
	int	res;

	res = ft_swap(&v->stack_b);
	ft_printf("sb\n");
	ft_fill_values(v);
	return (res);
}
// Prints the opposite because I misread the rules 
int	ft_pa(t_var *v)
{
	int	res;

	res = ft_push(&v->stack_a, &v->stack_b);
	v->size_a--;
	v->size_b++;
	ft_printf("pb\n");
	ft_fill_values(v);
	return (res);
}

// Prints the opposite because I misread the rules 
int	ft_pb(t_var *v)
{
	int	res;

	res = ft_push(&v->stack_b, &v->stack_a);
	v->size_a++;
	v->size_b--;
	ft_printf("pa\n");
	ft_fill_values(v);
	return (res);
}

// Prints the opposite because I misread the rules 
int	ft_pb_last(t_var *v)
{
	int	res;

	res = ft_push(&v->stack_b, &v->stack_a);
	v->size_a++;
	v->size_b--;
	ft_printf("pa\n");
	return (res);
}
