/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:46:22 by gsims             #+#    #+#             */
/*   Updated: 2024/01/23 09:45:45 by gsims            ###   ########.fr       */
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
    char            **dir;
    int             *cost;
    struct s_lst    *next;
    struct s_lst    *prev;
}                   t_lst;

typedef struct s_var
{
    t_lst   *stack_a;
    t_lst   *stack_b;
    char    **args;
    int     size_a;
    int     size_b;
    int     operations;
}           t_var;

void	ft_init_var(t_var *v, int ac, char *av[]);
int     ft_push(t_lst **stack_a, t_lst **stack_b);
int     ft_swap(t_lst **stack);
int     ft_rotate(t_lst **stack);
int     ft_rev_rotate(t_lst **stack);
int     get_max(t_lst *stack);
int     get_min(t_lst *stack);
void    ft_print_stacks(t_lst *stack_a, t_lst *stack_b);
void	ft_print_stacks_backup(t_lst *stack_a, t_lst *stack_b);
void	ft_lst_add_back(t_lst **lst, t_lst *new);
void	ft_lst_add_front(t_lst **lst, t_lst *new);
int	    ft_lst_size(t_lst *lst);
void	ft_lst_iter(t_lst *lst, void (*f)(void *));
t_lst	*ft_lst_new(void *content, void *idx, void *cost);
t_lst	*ft_lst_last(t_lst *lst);
char    **ft_input_check(int ac, char *av[]);
char	**ft_str_input_check(char *str);
void	ft_num_input_check(int i, int size, char *av[]);
void    ft_error(int errno, char *str);
int	    ft_count_array(char **array);
void    ft_free_array(char **array);
void    ft_free_stacks(t_var *v);
void    ft_free_all(t_var *v, char **array);
int     check_sort(t_lst *stack);
void	ft_print_array(char **array);
int     ft_sa(t_var *v);
int     ft_sb(t_var *v);
int     ft_ss(t_var *v);
int     ft_pa(t_var *v);
int     ft_pb(t_var *v);
int     ft_rrb(t_var *v);
int     ft_rra(t_var *v);
int     ft_rr(t_var *v);
int     ft_rb(t_var *v);
int     ft_ra(t_var *v);
int     ft_rrr(t_var *v);
int     ft_sort(t_var *v);
int     ft_sort_big(t_var *v);
int     ft_sort_small(t_var *v);
void    ft_fill_values(t_var *v);
void    ft_lst_idx(t_lst *stack);
void    ft_get_cost(t_lst *stack, int stack_size);
int     ft_get_steps_b(int num, t_lst *stack_b);
void    ft_fill_raw_cost(t_lst *stack, int stack_size);
void    ft_cost(t_var *v);
int     ft_sort_small(t_var *v);


#endif
