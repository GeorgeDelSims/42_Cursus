/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:02:30 by gsims             #+#    #+#             */
/*   Updated: 2024/02/13 13:54:18 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philosophers(t_data *d)
{
	int	i;
	int	thread;
	int	join;
	
	i = 0;
	while (i < d->number_of_philosophers)
	{
		thread = pthread_create(&d->philo[i]->thread_id, NULL, routine, (void *)&d->philo[i]);
		if (thread != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < d->number_of_philosophers)
	{
		if (d->philo[i]->thread_id == NULL)
			printf("d->philo[i]->thread_id is NULL\n");
		join = pthread_join(d->philo[i]->thread_id, NULL); // SEGFAULT here
		if (join != 0)
		{
			printf("problem wiht pthread_join\n");
			return (0);
		}
		i++;
	}
	return (0);
}
