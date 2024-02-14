/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:53:04 by gsims             #+#    #+#             */
/*   Updated: 2024/02/14 15:37:42 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


static void	ft_think(t_philo *philo)
{
	size_t	time;
	
	pthread_mutex_lock(philo->write_lock);
	philo->state = THINK;
	time = get_time() - philo->start_time;
	printf("%zu %d is thinking\n", time, (philo->id));
	pthread_mutex_unlock(philo->write_lock);
}

static void	ft_eat(t_philo *philo)
{
	size_t	time;
	
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->write_lock);
	philo->state = EAT;
	philo->meals_eaten++;
	usleep(1000 * philo->time_to_eat);
	time = get_time() - philo->start_time;
	printf("%zu %d is eating\n", time, philo->id);
	philo->last_meal = get_time();
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->write_lock);
}

static void	ft_sleep(t_philo *philo)
{
	size_t	time;
	
	pthread_mutex_lock(philo->write_lock);
	philo->state = SLEEP;
	usleep(1000 * philo->time_to_sleep);
	time = get_time() - philo->start_time;
	printf("%zu %d is sleeping\n", time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
}

// static void	ft_die(t_philo *philo)
// {
	// pthread_mutex_lock(philo->dead_lock);
	// *(philo->dead_flag) = 1;
	// pthread_mutex_unlock(philo->dead_lock);
// }

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;	
	philo->start_time = get_time();
	ft_think(philo);
	ft_eat(philo);
	ft_sleep(philo);
	// if (philo->last_meal - philo->start_time > philo->time_to_die)
		// ft_die(philo);
	return (NULL);
}