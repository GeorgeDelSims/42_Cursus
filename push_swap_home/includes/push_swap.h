/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:22 by gsims             #+#    #+#             */
/*   Updated: 2024/01/15 14:43:07 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_var
{
    t_list  *stack_a;
    t_list  *stack_b;
    int     size;
}           t_var;


int     ft_push(t_list **stack_a, t_list **stack_b);
int     ft_swap(t_list **stack);
int     ft_rotate(t_list **stack);
int     ft_rev_rotate(t_list **stack);
int     get_max(t_list *stack);
int     get_min(t_list *stack);
void    print_node(void *content);
void    ft_print_stacks(t_list *stack_a, t_list *stack_b);

#endif