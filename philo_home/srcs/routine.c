/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:53:04 by gsims             #+#    #+#             */
/*   Updated: 2024/02/14 13:42:21 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


static void	ft_think(t_philo *philo, size_t start_time)
{
	size_t	time;
	
	pthread_mutex_lock(philo->write_lock);
	philo->state = THINK;
	time = get_time() - start_time;
	printf("%zu %d is thinking\n", time, (philo->id));
	pthread_mutex_unlock(philo->write_lock);
}

static void	ft_eat(t_philo *philo, size_t start_time)
{
	size_t	time;
	
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->write_lock);
	usleep(1000 * philo->time_to_eat);
	philo->state = EAT;
	time = get_time() - start_time;
	printf("%zu %d is eating\n", time, philo->id);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->write_lock);
}

static void	ft_sleep(t_philo *philo, size_t start_time)
{
	size_t	time;
	
	pthread_mutex_lock(philo->write_lock);
	usleep(1000 * philo->time_to_sleep);
	philo->state = SLEEP;
	time = get_time() - start_time;
	printf("%zu %d is sleeping\n", time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
	
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;	
	philo->start_time = get_time();
	ft_think(philo, philo->start_time);
	ft_eat(philo, philo->start_time);
	ft_sleep(philo, philo->start_time);
	return (NULL);
}