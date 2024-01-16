/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:22 by gsims             #+#    #+#             */
/*   Updated: 2024/01/16 13:46:53 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_lst
{
    int             *content;
    int             *idx;
    int             *pos;
    struct s_lst    *next;
    struct s_lst    *prev;
}                   t_lst;

typedef struct s_var
{
    t_lst  *stack_a;
    t_lst  *stack_b;
    int     size;
}           t_var;

int     ft_push(t_lst **stack_a, t_lst **stack_b);
int     ft_swap(t_lst **stack);
int     ft_rotate(t_lst **stack);
int     ft_rev_rotate(t_lst **stack);
int     get_max(t_lst *stack);
int     get_min(t_lst *stack);
void    print_node(void *content);
void    ft_print_stacks(t_lst *stack_a, t_lst *stack_b);
void	ft_lst_add_back(t_lst **lst, t_lst *new);
void	ft_lst_add_front(t_lst **lst, t_lst *new);
int	    ft_lst_size(t_lst *lst);
void	ft_lst_iter(t_lst *lst, void (*f)(void *));
t_lst	*ft_lst_new(void *content);
t_lst	*ft_lst_last(t_lst *lst);
char    **ft_input_check(int ac, char *av[]);
char	**ft_str_input_check(char *str);
void	ft_num_input_check(int size, char *av[]);
void    error(int errno, char *str);
int	    ft_count_array(char **array);

#endif