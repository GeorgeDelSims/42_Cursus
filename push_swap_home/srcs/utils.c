/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:11:31 by georgesims        #+#    #+#             */
/*   Updated: 2024/01/30 15:07:39 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_count_array(char **array)
{
	int	count;

	count = 0;
	while (array[count])
		count++;
	return (count);
}

void	ft_error(int errno, char *str)
{
	ft_printf("Error:\n%s\n", str);
	exit(errno);
}

void	refresh_min_max_a(t_var *v)
{
	v->max_a = get_max(v->stack_a);
	v->min_a = get_min(v->stack_a);
}
