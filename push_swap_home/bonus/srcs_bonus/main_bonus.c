/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:19:31 by gsims             #+#    #+#             */
/*   Updated: 2024/02/05 10:28:16 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/checker.h"

// Checker gets given the same list of chars 
// turns them into a linked list just like push_swap 
// calls push swap to get the commands for sorting
// reads the commands from STDOUT line by line 
// applies the commands to the linked list
// Checks the list is sorted 
// Returns OK, KO or Error depending on the result 

//
//


// Initiate variables and check input
void	ft_init_var_check(t_var *vc, int ac, char *av[])
{
	int		size_a;
	
	vc->args = ft_input_check(ac, av);
	size_a = ft_count_array(vc->args);
	vc->size_a = ft_init_a(vc, size_a, ac, vc->args);
	// refresh_min_max_a(vc);
}

// Initiates a char ** array with the commands 
// printed by push_swap in the STDin (0) of the checker
// void	ft_init_cmds(t_var *vc)
// {
	// int	i;
	// 
	// i = 0;
	// vc->cmds = (char **)malloc(sizeof(char **));
	// if (!vc->cmds)
		// ft_error(1, "cmds malloc failed");
	// while (vc->cmds[i] != NULL)
	// {
		// vc->cmds[i] = (char *)malloc(sizeof(char *));
		// vc->cmds[i] = get_next_line(0);
		// i++;
	// }
// }
// 

void	ft_apply_cmds(char *cmd, t_var *vc)
{
	if (cmd == "pa")
		
	else if (cmd == "pb")
		ft_push(vc->stack_b, vc->stack_a);
	else if (cmd == "pb")
		ft_push(vc->stack_a, vc->stack_b);
	else if (cmd == "sa")
		ft_swap(vc->stack_a);
	else if (cmd == "sb")
		ft_swap(vc->stack_b);
	else if (cmd == "ss")
	{
		ft_swap(vc->stack_b);
		ft_swap(vc->stack_a);
	}
	else if (cmd == "ra")
		ft_rotate(vc->stack_a);
	else if (cmd == "rb")
		ft_rotate(vc->stack_b);
	else if (cmd == "rr")
	{
		ft_rotate(vc->stack_a);
		ft_rotate(vc->stack_b);
	}
	else if (cmd == "rra")
		ft_rev_rotate(vc->stack_a);
	else if (cmd == "rrb")
		ft_rev_rotate(vc->stack_b);
	else if (cmd == "rrr")
	{
		ft_rev_rotate(vc->stack_a);
		ft_rev_rotate(vc->stack_b);
	}
}


// Loops through the list of cmds and applies them to the bonus stacks
void	ft_loop(t_var *vc)
{
	char	**temp;

	while (temp)
	{
		temp = (char *)malloc(sizeof(char *));
		if (!temp)
			ft_error(1, "temp malloc failed");
		temp = get_next_line(0);
		ft_apply_cmds(temp, vc);
		free(temp);
	}
}


int	main(int ac, char *av[])
{
	t_var	*vc;

	vc = (t_var *)malloc(sizeof(t_var *));
	if (!vc)
		ft_error(1, "vc malloc failed\n");
	ft_init_var_check(vc, ac, av);
	//ft_print_stacks(vc->stack_a, vc->stack_b);
	ft_loop(vc);
	ft_printf("checker checked\n");
	return (0);
}