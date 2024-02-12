/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:06:46 by gsims             #+#    #+#             */
/*   Updated: 2024/02/12 15:52:20 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// initiate values from argv[]
static void	init_args(t_data *d, char *av[])
{
	d->number_of_philosophers = ft_atoi(av[1]);
	d->time_to_die = ft_atoi(av[2]);
	d->time_to_eat = ft_atoi(av[3]);
	d->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		d->number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
}

// initiate mutex locks + args
int	init_data(t_data *d, char *av[])
{
	if (!av || !d)
		return (0);
	pthread_mutex_init(&d->write_lock, NULL);
	pthread_mutex_init(&d->dead_lock, NULL);
	pthread_mutex_init(&d->meal_lock, NULL);
	init_args(d, av);
	return (1);
}
