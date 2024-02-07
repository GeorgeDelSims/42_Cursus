/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:19:31 by gsims             #+#    #+#             */
/*   Updated: 2024/02/06 16:45:47 by gsims            ###   ########.fr       */
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

// Initiate variables and check input
void	ft_init_var_check(t_var *vc, int ac, char *av[])
{
	int		size_a;

	ft_printf("av[1] : %s\n", av[1]);
	vc->args = ft_input_check(ac, av);
	size_a = ft_count_array(vc->args);
	vc->size_a = ft_init_a(vc, size_a, ac, vc->args);
	vc->stack_b = NULL;
	// refresh_min_max_a(vc);
}

// returns 1 if strings are the same, 0 if they are different
int	ft_strcmp(char *s1, char * s2)
{
	int	i;
	
	if (!s1 || !s2 || ft_strlen(s1) != ft_strlen(s2))
		return (0);
	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

// Applies all commands according to the STDin 
void	ft_apply_cmds(char *cmd, t_var *vc)
{
	if (ft_strcmp(cmd, "pa") == 1)
		ft_push(&vc->stack_b, &vc->stack_a);		
	else if (ft_strcmp(cmd, "pb") == 1)
		ft_push(&vc->stack_a, &vc->stack_b);
	else if (ft_strcmp(cmd, "sa") == 1)
		ft_swap(&vc->stack_a);
	else if (ft_strcmp(cmd, "sb") == 1)
		ft_swap(&vc->stack_b);
	else if (ft_strcmp(cmd, "ss") == 1)
	{
		ft_swap(&vc->stack_b);
		ft_swap(&vc->stack_a);
	}
	else if (ft_strcmp(cmd, "ra") == 1)
		ft_rotate(&vc->stack_a);
	else if (ft_strcmp(cmd, "rb") == 1)
		ft_rotate(&vc->stack_b);
	else if (ft_strcmp(cmd, "rr") == 1)
	{
		ft_rotate(&vc->stack_a);
		ft_rotate(&vc->stack_b);
	}
	else if (ft_strcmp(cmd, "rra") == 1)
		ft_rev_rotate(&vc->stack_a);
	else if (ft_strcmp(cmd, "rrb") == 1)
		ft_rev_rotate(&vc->stack_b);
	else if (ft_strcmp(cmd, "rrr") == 1)
	{
		ft_rev_rotate(&vc->stack_a);
		ft_rev_rotate(&vc->stack_b);
	}
}


// Loops through the list of cmds and applies them to the bonus stacks
void	ft_check_loop(t_var *vc)
{
	char	*temp;

	write(STDOUT_FILENO, "Before GNL\n", 11);
	while (1)
	{
		temp = get_next_line(0);
		if (temp[0] == '\0' || ft_strcmp(temp, "\n") == 1 || temp == NULL)
		{
			free(temp);
			break ;
		}
		ft_apply_cmds(temp, vc);
		free(temp);
	}
}

int	main(int ac, char *av[])
{
	t_var	*vc;
	int		check;

	vc = (t_var *)malloc(sizeof(t_var));
	if (!vc)
		ft_error(1, "Error\n");
	ft_init_var_check(vc, ac, av);
	ft_check_loop(vc);
	check = check_sort_a(vc->stack_a);
	ft_free_lst(&vc->stack_a);
	free(vc);
	if (check == 1)
		ft_error(1, "OK\n");
	else
		ft_error(1, "KO\n");
	return (0);
}
