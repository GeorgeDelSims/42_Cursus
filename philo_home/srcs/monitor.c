/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:49:10 by gsims             #+#    #+#             */
/*   Updated: 2024/02/27 11:48:47 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// Check dead flag and print out death message
static void	ft_dead(t_data *d, int i)
{
	pthread_mutex_lock(&d->dead_lock);
	d->dead_flag = 1;
	d->dead_philo_index = i;
	pthread_mutex_unlock(&d->dead_lock);
}

// Check if all philos have had enough meals
static int	enough_meals(t_data *d)
{
	int	i;

	i = 0;
	while (i < d->number_of_philosophers)
	{
		pthread_mutex_lock(&d->philo[i]->meals_eaten.lock);
		if (d->philo[i]->meals_eaten.value < (size_t)d->eat_number)
		{
			pthread_mutex_unlock(&d->philo[i]->meals_eaten.lock);
			return (0);
		}
		pthread_mutex_unlock(&d->philo[i]->meals_eaten.lock);
		i++;
	}
	return (1);
}

// Meal monitor function (just for shortening the monitor one)
static int	meal_monitor(t_data *d)
{
	if (d->eat_number)
	{
		pthread_mutex_lock(&d->meal_lock);
		if (enough_meals(d) == 1)
		{
			d->meal_flag = 1;
			pthread_mutex_unlock(&d->meal_lock);
			d->end_flag = 1;
			return (1);
		}
		pthread_mutex_unlock(&d->meal_lock);
	}
	return (0);
}

// Main Monitor Function
void	*monitor(void *data)
{
	int		i;
	t_data	*d;

	d = (t_data *)data;
	i = 0;
	while (1)
	{
		if (meal_monitor(d) == 1)
			break ;
		pthread_mutex_lock(&d->philo[i]->last_meal.lock);
		if (get_time() - d->philo[i]->last_meal.value > d->philo[i]->time_to_die)
		{
			pthread_mutex_unlock(&d->philo[i]->last_meal.lock);
			ft_dead(d, i);
			break ;
		}
		else
			pthread_mutex_unlock(&d->philo[i]->last_meal.lock);
		i = (i + 1) % d->number_of_philosophers;
		usleep(53);
	}
	return (NULL);
}

// Monitor thread that runs continuously and checks if the meal_flag is up
void	*meal_stop_monitor(void *data)
{
	t_data	*d;

	d = (t_data *)data;
	while(1)
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
	while(1)
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

/*
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
			if (enough_meals(d) == 1)
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
*/