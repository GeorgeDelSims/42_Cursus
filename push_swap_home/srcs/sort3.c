/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 11:47:00 by gsims             #+#    #+#             */
/*   Updated: 2024/01/30 11:49:05 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_five(t_var *v)
{
	
}

void	ft_sort_small(t_var *v)
{
	if (v->size_a < 4)
		ft_sort_three(v);
	else
		ft_sort_five(v);	
}