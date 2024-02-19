/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:49:10 by gsims             #+#    #+#             */
/*   Updated: 2024/02/19 16:14:20 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	ft_dead(t_data *d, int i)
{
	pthread_mutex_lock(&d->dead_lock);
	d->dead_flag = 1;
	pthread_mutex_unlock(&d->dead_lock);
	pthread_mutex_lock(&d->write_lock);
	printf("\033[31m%zu %d died\n\033[0m", get_time() - d->start_time,
		d->philo[i]->id);
	pthread_mutex_unlock(&d->write_lock);
}

static void	ft_meal(t_data *d, int i)
{
	pthread_mutex_lock(&d->meal_lock);
	d->meal_flag = 1;
	pthread_mutex_lock(&d->write_lock);
	printf("All philosophers have eaten %d meals : %zu\n",
		d->philo[i]->meals_eaten, get_time() - d->start_time);
	pthread_mutex_unlock(&d->write_lock);
	pthread_mutex_unlock(&d->meal_lock);
}


static int	enough_meals_yeah(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philosophers)
	{
		if (d->philo[i]->meals_eaten < d->eat_number)
			return (0);
		i++;
	}
	return (1);
}

// Clause for if the philos have spent too much time sleeping/thinking
// if time since last meal > time_to_die && philo->state != EAT
// Clause for if the max amount of meals per philosopher has been reached
void	*monitor(void *data)
{
	int		i;
	t_data	*d;

	d = (t_data *)data;
	i = 0;
	while (1)
	{
		if (d->eat_number)
		{
			pthread_mutex_lock(&d->meal_lock);
			if (enough_meals_yeah(d) == 1)
			{
				pthread_mutex_unlock(&d->meal_lock);
				ft_meal(d, i);
				break ;
			}
			pthread_mutex_unlock(&d->meal_lock);
		}
		pthread_mutex_lock(&d->meal_lock);
		if (get_time() - d->philo[i]->last_meal > d->philo[i]->time_to_die)
		{
			ft_dead(d, i);
			pthread_mutex_unlock(&d->meal_lock);
			break ;
		}
		pthread_mutex_unlock(&d->meal_lock);
		i = (i + 1) % d->number_of_philosophers;
	}
	return (NULL);
}
