/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:02:30 by gsims             #+#    #+#             */
/*   Updated: 2024/02/14 10:38:14 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philosophers(t_data *d)
{
	int	i;
	int	thread;
	// int	join;
	
	i = 0;
	while (i < d->number_of_philosophers)
	{
		thread = pthread_create(&d->philo[i]->thread_id, NULL, routine, (void *)d->philo[i]);
		// printf("Thread ID: %lu\n", (unsigned long)d->philo[i]->thread_id);
		if (thread != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < d->number_of_philosophers)
	{
		pthread_join(d->philo[i]->thread_id, NULL); // SEGFAULT here
		i++;
	}
	return (0);
}
