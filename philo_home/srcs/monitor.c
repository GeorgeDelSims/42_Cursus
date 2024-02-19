/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:49:10 by gsims             #+#    #+#             */
/*   Updated: 2024/02/19 10:32:20 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Clause for if the philos have spent too much time sleeping/thinking
// if time since last meal > time_to_die && philo->state != EAT
// Clause for if the max amount of meals per philosopher has been reached
void	*monitor(void *data)
{
	int		i;
	t_data	*d;
	
	d = (t_data *)data;
	i = 0;
	while(1)
	{
		if (d->number_of_times_each_philosopher_must_eat)
		{
			if (d->philo[i]->meals_eaten >= d->number_of_times_each_philosopher_must_eat)
			{
				d->meal_flag = 1;
				pthread_mutex_lock(&d->write_lock);
				printf("philo %d has eaten %d meals : %zu\n", d->philo[i]->id, d->philo[i]->meals_eaten, get_time() - d->start_time);
				break ;
			}
		}
		if (get_time() - d->philo[i]->last_meal > d->philo[i]->time_to_die)
		{
			pthread_mutex_lock(&d->dead_lock);
			d->dead_flag = 1;
			pthread_mutex_unlock(&d->dead_lock);
			pthread_mutex_lock(&d->write_lock);
			printf("\033[31m%zu %d died\n\033[0m", get_time() - d->start_time, d->philo[i]->id);
			break ;
		}
		i = (i + 1) % d->number_of_philosophers;
	}
	return (NULL);
}
