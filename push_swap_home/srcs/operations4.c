/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 10:34:38 by gsims             #+#    #+#             */
/*   Updated: 2024/01/30 10:35:12 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_sa(t_var *v)
{
	int	res;

	res = ft_swap(&v->stack_a);
	ft_printf("sa\n");
	ft_fill_values(v);
	return (res);
}
