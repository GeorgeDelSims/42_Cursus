/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_monitors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 14:04:17 by gsims             #+#    #+#             */
/*   Updated: 2024/02/27 14:04:36 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Monitor thread that runs continuously and checks if the meal_flag is up
void	*meal_stop_monitor(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	while (1)
	{
		pthread_mutex_lock(&d->meal_lock);
		if (d->meal_flag == 1)
		{
			pthread_mutex_unlock(&d->meal_lock);
			join_all_threads(d);
			break ;
		}
		else
			pthread_mutex_unlock(&d->meal_lock);
		usleep(50);
	}
	return (NULL);
}

// Monitor thread that runs continuously and checks if the dead_flag is up
void	*dead_stop_monitor(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	while (1)
	{
		pthread_mutex_lock(&d->dead_lock);
		if (d->dead_flag == 1)
		{
			print_philo_dead(d->philo[d->dead_philo_index], "is dead");
			pthread_mutex_unlock(&d->dead_lock);
			join_all_threads(d);
			break ;
		}
		else
			pthread_mutex_unlock(&d->dead_lock);
		usleep(100);
	}
	return (NULL);
}
