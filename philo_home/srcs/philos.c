/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:02:30 by gsims             #+#    #+#             */
/*   Updated: 2024/02/27 12:57:02 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_all_threads(t_data *d)
{
	int	i;
	
	i = 0;
	while (i < d->number_of_philosophers)
	{
		if (d->philo[i]->thread_id)
			pthread_join(d->philo[i]->thread_id, NULL);
		i++;
	}
	// pthread_join(d->monitor_id, NULL);
	// pthread_join(d->dead_monitor_id, NULL);
	// pthread_join(d->meal_monitor_id, NULL);
}

int	philosophers(t_data *d)
{
	int	i;

	i = 0;
	d->threads = malloc(sizeof(int) * d->number_of_philosophers);
	if (!d->threads)
		return (0);
	pthread_create(&d->dead_monitor_id, NULL, dead_stop_monitor, (void *)d);
	pthread_detach(d->dead_monitor_id);
	pthread_create(&d->meal_monitor_id, NULL, meal_stop_monitor, (void *)d);
	pthread_detach(d->meal_monitor_id);
	pthread_create(&d->monitor_id, NULL, monitor, (void *)d);
	pthread_detach(d->monitor_id);
	while (i < d->number_of_philosophers)
	{
		d->threads[i] = pthread_create(&d->philo[i]->thread_id, NULL, routine,
				(void *)d->philo[i]);
		if (d->threads[i] != 0)
			return (0);
		usleep(23);
		i++;
	}
	join_all_threads(d);
	return (0);
}

void	case_one(t_data *d)
{
	d->threads[0] = pthread_create(&d->philo[0]->thread_id, NULL, routine,
		(void *)d->philo[0]);
	pthread_detach(d->philo[0]->thread_id);
}