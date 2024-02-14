/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:49:10 by gsims             #+#    #+#             */
/*   Updated: 2024/02/14 16:10:19 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Clause for if the philos have spent too much time sleeping/thinking
// if time since last meal > time_to_die && philo->state != EAT
// Clause for if the max amount of meals per philosopher has been reached
void	*monitor(void *data)
{
	int	i; 
	t_data	*d;
	
	d = data;
	i = 0;
	while(1)
	{
		if (get_time() - d->philo[i]->last_meal)
		{
			pthread_mutex_lock(&d->dead_lock);
			d->dead_flag = 1;
			pthread_mutex_unlock(&d->dead_lock);
			break ;
		}
		if (d->number_of_times_each_philosopher_must_eat)
		{
			if (d->philo[i]->meals_eaten > d->number_of_times_each_philosopher_must_eat)
				break ;
		}
		i++;
	}
	return (NULL);
}
