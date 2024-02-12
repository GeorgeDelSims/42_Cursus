/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:37:28 by gsims             #+#    #+#             */
/*   Updated: 2024/02/12 15:58:04 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*
Functions needed:
- A launch_thread function for launching each thread (=philosopher)
		-> This function will be called in a loop (while number of philosophers)
- Eat + sleep + think functions with mutex locks and which change the state of 
	each philosopher -> don't forget to destroy the mutex at the end
- A routine function that calls the eat, sleep, think functions 
		-> it should also malloc each philo struct
- a monitor function / thread with a while(1) loop that breaks if dead_flag = 1 
or if time_to_die has surpassed time_to_eat


*/

int	main(int ac, char *av[])
{
	t_data	*d;
	
	if ((input_check(ac, av)) == 0)
	{
		printf("input incorrect\n");
		return (0);
	}
	d = (t_data *)malloc(sizeof(t_data));
	if (!d)
		return (0);	
	if (init_data(d, av) == 0)
		return (0);
	// execute()
	// ft_free()
	return (0);
}
