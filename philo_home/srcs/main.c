/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:37:28 by gsims             #+#    #+#             */
/*   Updated: 2024/02/20 18:29:17 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	philosophers(d);
	free_all(d);
	// pthread_mutex_lock(&d->dead_lock);
	// if (d->dead_flag == 1)
		// print_philo(d->philo[d->dead_philo_index], "is dead");
	// pthread_mutex_unlock(&d->dead_lock);
	return (0);
}
