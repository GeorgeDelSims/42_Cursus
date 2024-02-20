/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 10:06:46 by gsims             #+#    #+#             */
/*   Updated: 2024/02/20 17:43:01 by gsims            ###   ########.fr       */
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
		d->eat_number = ft_atoi(av[5]);
}

// Initiate right fork for each philosopher
// --> (pointer to left fork of the next philosopher)
static void	init_right_fork(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philosophers)
	{
		d->philo[i]->r_fork = d->philo[(i + 1)
			% d->number_of_philosophers]->l_fork;
		i++;
	}
}

// initialise philosopher-specific values that need mutexes
static void	init_shared_values(t_philo *philo)
{
	philo->meals_eaten.value = 0;
	pthread_mutex_init(&philo->meals_eaten.lock, NULL);
	pthread_mutex_init(&philo->last_meal.lock, NULL);
}

// Initiate philosophers & Forks
static void	init_philos(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philosophers)
	{
		d->philo[i] = malloc(sizeof(t_philo));
		d->philo[i]->l_fork = malloc(sizeof(pthread_mutex_t));
		if (!d->philo[i] || !d->philo[i]->l_fork)
			printf("malloc error -> init_philos\n");
		d->philo[i]->d = d;
		d->philo[i]->id = i + 1;
		d->philo[i]->time_to_die = (size_t)d->time_to_die;
		d->philo[i]->time_to_sleep = (size_t)d->time_to_sleep;
		d->philo[i]->time_to_eat = (size_t)d->time_to_eat;
		d->philo[i]->write_lock = &d->write_lock;
		d->philo[i]->dead_lock = &d->dead_lock;
		d->philo[i]->meal_lock = &d->meal_lock;
		pthread_mutex_init(d->philo[i]->l_fork, NULL);
		init_shared_values(d->philo[i]);
		d->philo[i]->last_meal.value = d->start_time;
		i++;
	}
}

// initiate colour array
void	init_colours(t_data *d)
{
	d->colours[0] = GREEN;
	d->colours[1] = YELLOW;
	d->colours[2] = BLUE;
	d->colours[3] = PURPLE;
	d->colours[4] = CYAN;
	d->colours[5] = RED;
}

// initiate mutex locks + args
int	init_data(t_data *d, char *av[])
{
	if (!av || !d)
		return (0);
	memset(d, 0, sizeof(t_data));
	pthread_mutex_init(&d->write_lock, NULL);
	pthread_mutex_init(&d->dead_lock, NULL);
	pthread_mutex_init(&d->meal_lock, NULL);
	init_args(d, av);
	init_colours(d);
	d->philo = malloc(sizeof(t_philo *) * (d->number_of_philosophers));
	if (!d->philo)
	{
		printf("malloc error d->philo in init_data\n");
		return (0);
	}
	d->start_time = get_time();
	init_philos(d);
	init_right_fork(d);
	return (1);
}
