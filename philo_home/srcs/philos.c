/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:02:30 by gsims             #+#    #+#             */
/*   Updated: 2024/02/15 11:28:57 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philosophers(t_data *d)
{
	int	i;
	int	thread[d->number_of_philosophers];
	
	i = 0;
	pthread_create(&d->monitor_id, NULL, monitor, (void *)d);
	while (i < d->number_of_philosophers)
	{
		thread[i] = pthread_create(&d->philo[i]->thread_id, NULL, routine, (void *)d->philo[i]);
		if (thread[i] != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < d->number_of_philosophers)
	{
		if (d->philo[i]->thread_id)
			pthread_join(d->philo[i]->thread_id, NULL);
		i++;
	}
	pthread_join(d->monitor_id, NULL);
	return (0);
}
