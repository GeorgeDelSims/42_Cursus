/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgesims <georgesims@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:22 by gsims             #+#    #+#             */
/*   Updated: 2024/01/11 14:51:32 by georgesims       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int ft_push(t_list **stack_a, t_list **stack_b);
int ft_swap(t_list **stack);
int ft_rotate(t_list **stack);
int ft_rev_rotate(t_list **stack);

#endif