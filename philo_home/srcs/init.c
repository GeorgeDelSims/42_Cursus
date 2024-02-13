/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:06:46 by gsims             #+#    #+#             */
/*   Updated: 2024/02/13 12:08:42 by gsims            ###   ########.fr       */
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

// Initiate philosophers & Forks 
static void	init_philos(t_data *d)
{
	int	i;
	
	i = 0;
	while (i < d->number_of_philosophers)
	{
		d->philo[i] = malloc(sizeof(t_philo));
		d->philo[i]->id = i;
		d->philo[i]->state = THINK;
		d->philo[i]->meals_eaten = 0;
		d->philo[i]->write_lock = malloc(sizeof(pthread_mutex_t *));
		d->philo[i]->dead_lock = malloc(sizeof(pthread_mutex_t *));
		d->philo[i]->meal_lock = malloc(sizeof(pthread_mutex_t *));
		d->philo[i]->l_fork = malloc(sizeof(pthread_mutex_t *));
		if (!d->philo[i]->write_lock || !d->philo[i]->dead_lock 
			|| !d->philo[i]->meal_lock || !d->philo[i]->l_fork)
			printf("malloc error -> init_philos\n");
		d->philo[i]->write_lock = &d->write_lock;
		d->philo[i]->dead_lock = &d->dead_lock;
		d->philo[i]->meal_lock = &d->meal_lock;
		pthread_mutex_init(d->philo[i]->l_fork, NULL);
		d->philo[i]->r_fork = d->philo[(i + 1) % d->number_of_philosophers]->l_fork;
		i++;
	}
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
	d->philo = malloc(sizeof(t_philo *) * d->number_of_philosophers);
	if (!d->philo)
		return (0);
	init_philos(d);
	return (1);
}
