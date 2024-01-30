/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:23:43 by gsims             #+#    #+#             */
/*   Updated: 2024/01/30 15:01:26 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_array(char **array)
{
	int	size;
	int	i;

	size = ft_count_array(array);
	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	ft_free_node(t_lst *node)
{
	if (node)
	{
		free(node->content);
		free(node->idx);
		free(node->cost);
		free(node);
	}
}

static void	ft_free_lst(t_lst **lst)
{
	t_lst	*current;
	t_lst	*next;

	if (!lst || !*lst)
		return ;
	current = *lst;
	while (current)
	{
		next = current->next;
		ft_free_node(current);
		current = next;
	}
	*lst = NULL;
}

void	ft_free_stacks(t_var *v)
{
	ft_free_lst(&v->stack_a);
	ft_free_lst(&v->stack_b);
	free(v);
}

void	ft_free_all(t_var *v, char **array)
{
	ft_free_array(array);
	ft_free_stacks(v);
}
