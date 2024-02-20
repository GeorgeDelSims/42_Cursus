/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:53:04 by gsims             #+#    #+#             */
/*   Updated: 2024/02/20 11:46:17 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	stop_threads(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead_flag) == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_lock(philo->meal_lock);
	if (*(philo->meal_flag) == 1)
	{
		pthread_mutex_unlock(philo->meal_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->meal_lock);
	return (0);
}

static void	ft_think(t_philo *philo)
{
	if (stop_threads(philo) == 1)
		return ;
	print_philo(philo, "is thinking");	
	if (stop_threads(philo) == 1)
		return ;
}

// increment mmeals_eaten + get time for last meal
static void	increment_meals(t_philo *philo)
{
	pthread_mutex_lock(philo->meal_lock);
	philo->meals_eaten++;
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->meal_lock);	
}

static void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_philo(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	print_philo(philo, "has taken a fork");
	print_philo(philo, "is eating");
	increment_meals(philo);
	if (stop_threads(philo) == 1)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static void	ft_sleep(t_philo *philo)
{
	size_t	time;

	if (stop_threads(philo) == 1)
		return ;
	time = get_time() - *(philo->start_time);
	print_philo(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
	if (stop_threads(philo) == 1)
		return ;
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (stop_threads(philo) == 1)
			break ;
		ft_think(philo);
		if (stop_threads(philo) == 1)
			break ;
		ft_eat(philo);
		if (stop_threads(philo) == 1)
			break ;
		ft_sleep(philo);
		if (stop_threads(philo) == 1)
			break ;
	}
	return (NULL);
}
