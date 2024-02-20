/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:02:30 by gsims             #+#    #+#             */
/*   Updated: 2024/02/20 15:03:34 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	terminate_all_threads(t_data *d)
{
	int	i;
	
	i = 0;
	while (i < d->number_of_philosophers)
	{
		if (d->philo[i]->thread_id)
			pthread_join(d->philo[i]->thread_id, NULL);
		i++;
	}
}

int	philosophers(t_data *d)
{
	int	i;

	i = 0;
	d->threads = malloc(sizeof(int) * d->number_of_philosophers);
	if (!d->threads)
		return (0);
	pthread_create(&d->monitor_id, NULL, monitor, (void *)d);
	pthread_create(&d->dead_monitor_id, NULL, dead_stop_monitor, (void *)d);
	pthread_create(&d->meal_monitor_id, NULL, meal_stop_monitor, (void *)d);
	while (i < d->number_of_philosophers)
	{
		d->threads[i] = pthread_create(&d->philo[i]->thread_id, NULL, routine,
				(void *)d->philo[i]);
		if (d->threads[i] != 0)
			return (0);
		i++;
	}
	terminate_all_threads(d);
	pthread_join(d->monitor_id, NULL);
	pthread_join(d->dead_monitor_id, NULL);
	pthread_join(d->meal_monitor_id, NULL);
	return (0);
}
