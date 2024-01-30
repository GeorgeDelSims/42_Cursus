/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:22 by gsims             #+#    #+#             */
/*   Updated: 2024/01/30 11:19:57 by gsims            ###   ########.fr       */
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
    int             *cost;
    struct s_lst    *next;
}                   t_lst;

typedef struct s_var
{
    t_lst   *stack_a;
    t_lst   *stack_b;
    char    **args;
    int     size_a;
    int     size_b;
    int     min_a;
    int     min_b;
    int     max_a;
    int     max_b;
    int     operations;
}           t_var;

typedef struct  s_sort
{
    int idx;
    int idx_b;
    int double_ops;
    int cost;
}       t_sort;

void	ft_init_var(t_var *v, int ac, char *av[]);
int     ft_push(t_lst **stack_a, t_lst **stack_b);
int     ft_swap(t_lst **stack);
int     ft_rotate(t_lst **stack);
int     ft_rev_rotate(t_lst **stack);
int     get_max(t_lst *stack);
int     get_min(t_lst *stack);
void    ft_print_stacks(t_lst *stack_a, t_lst *stack_b);
void	ft_print_stacks_backup(t_lst *stack_a, t_lst *stack_b);
void	ft_lst_add_back(t_lst **lst, t_lst *new_node);
void	ft_lst_add_front(t_lst **lst, t_lst *new_node);
int	    ft_lst_size(t_lst *lst);
void	ft_lst_iter(t_lst *lst, void (*f)(void *));
t_lst	*ft_lst_new(void *content, void *idx, void *cost);
t_lst	*ft_lst_last(t_lst *lst);
char    **ft_input_check(int ac, char *av[]);
void    ft_error(int errno, char *str);
int	    ft_count_array(char **array);
void    ft_free_array(char **array);
void    ft_free_stacks(t_var *v);
void    ft_free_all(t_var *v, char **array);
int     check_sort_a(t_lst *stack);
int	    check_sort_b(t_lst *stack);
void	ft_print_array(char **array);
int     ft_sb(t_var *v);
int     ft_sa(t_var *v);
int     ft_pa(t_var *v);
int     ft_pa_start(t_var *v);
int     ft_pb(t_var *v);
int     ft_pb_last(t_var *v);
int     ft_rrb(t_var *v);
int     ft_rra(t_var *v);
int     ft_rr(t_var *v);
int     ft_rb(t_var *v);
int     ft_ra(t_var *v);
int     ft_rrr(t_var *v);
void    ft_sort(t_var *v);
int     ft_sort_big(t_var *v);
void    ft_fill_values(t_var *v);
void    ft_lst_idx(t_lst *stack);
void    ft_get_cost(t_lst *stack, int stack_size);
int     ft_get_steps_brut(int num, t_lst *stack_b);//, t_var *v);
void    ft_fill_raw_cost(t_lst *stack, int stack_size);
void    ft_cost(t_var *v);
t_lst   *ft_find_cheapest(t_var *v);
int     ft_operator_first_half(t_var *v, t_lst *cheap, int rr, int ra);
void    ft_back_to_top(t_var *v);
void    ft_sort_three(t_var *v);


#endif
