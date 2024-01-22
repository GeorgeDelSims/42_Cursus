/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 09:42:59 by gsims             #+#    #+#             */
/*   Updated: 2024/01/22 16:13:13 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sa(t_var *v)
{
	int	res;
	
	res = ft_swap(&v->stack_a);
	ft_printf("sa\n");
	return (res);
}

int	ft_sb(t_var *v)
{
	int	res;
	
	res = ft_swap(&v->stack_b);
	ft_printf("sb\n");
	return (res);
}

int	ft_ss(t_var *v)
{	
	ft_sa(v);
	ft_sb(v);
	ft_printf("ss\n");
	return (1);
}

int ft_pa(t_var *v)
{
	int	res;

	res = ft_push(&v->stack_a, &v->stack_b);
	v->size_a--;
	v->size_b++;
	ft_printf("pa\n");
	//ft_printf("size_a : %d\n", v->size_a);
	//ft_printf("size_b : %d\n", v->size_b);
	ft_fill_values(v);
	return(res);
}

int ft_pb(t_var *v)
{
	int	res;
	res = ft_push(&v->stack_b, &v->stack_a);
	v->size_a--;
	v->size_b++;
	ft_printf("pb\n");
	return(res);
}
