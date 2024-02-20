/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:53:04 by gsims             #+#    #+#             */
/*   Updated: 2024/02/20 14:32:28 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// increment mmeals_eaten + get time for last meal
static void	increment_meals(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);	
}

// updates the value of the last_meal variable
static void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->meal_lock);	
}

// eat state main function
static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_philo(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	print_philo(philo, "has taken a fork");
	print_philo(philo, "is eating");
	update_last_meal(philo);
	if (stop_threads(philo) == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	ft_usleep(philo->time_to_eat);
	increment_meals(philo);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

// sleep function for the routine
static void	ft_sleep(t_philo *philo)
{
	if (stop_threads(philo) == 1)
		return ;
	print_philo(philo, "is sleeping");
	if (stop_threads(philo) == 1)
		return ;
	ft_usleep(philo->time_to_sleep);
	if (stop_threads(philo) == 1)
		return ;
}
// Routine function 
void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		print_philo(philo, "is thinking");	
		ft_eat(philo);
		ft_sleep(philo);
		if (stop_threads(philo) == 1)
			break ;
	}
	return (NULL);
}