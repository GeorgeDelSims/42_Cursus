/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:37:28 by gsims             #+#    #+#             */
/*   Updated: 2024/02/27 11:57:27 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// new variable for printed_dead_flag  -> just prevent printing if dead_flag == 1
// conditional usleep on sleep and eat functions -> if time_to_die < time_to_eat -> sleep time to die
// Main function
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
	if (d->number_of_philosophers != 1)
		philosophers(d);
	else 
		case_one(d);
	free_all(d);
	// pthread_mutex_lock(&d->dead_lock);
	// if (d->dead_flag == 1)
		// print_philo(d->philo[d->dead_philo_index], "is dead");
	// pthread_mutex_unlock(&d->dead_lock);
	return (0);
}
