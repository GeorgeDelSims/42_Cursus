/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:02:30 by gsims             #+#    #+#             */
/*   Updated: 2024/02/13 11:19:41 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philosophers(t_data *d)
{
	int	i;
	int	thread;
	
	i = 0;
	while (i < d->number_of_philosophers)
	{
		thread = pthread_create(&d->philo[i]->thread_id, NULL, routine, (void *)&d->philo[i]);
		if (thread != 0)
			return (0);
		pthread_join(d->philo[i]->thread_id, NULL);
		i++;
	}
	return (0);
}