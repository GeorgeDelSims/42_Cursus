/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 08:05:48 by gsims             #+#    #+#             */
/*   Updated: 2024/02/27 13:31:13 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Frees pointers, structs and destroys mutexes at the same time
void	free_all(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philosophers)
	{
		if (d->philo[i]->l_fork)
		{
			free(d->philo[i]->l_fork);
			pthread_mutex_destroy(d->philo[i]->l_fork);
			pthread_mutex_destroy(&d->philo[i]->meals_eaten.lock);
			pthread_mutex_destroy(&d->philo[i]->last_meal.lock);
		}
		free(d->philo[i]);
		i++;
	}
	free(d->threads);
	pthread_mutex_destroy(&d->dead_lock);
	pthread_mutex_destroy(&d->write_lock);
	pthread_mutex_destroy(&d->meal_lock);
	free(d->philo);
	free(d);
}
