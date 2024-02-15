/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:53:04 by gsims             #+#    #+#             */
/*   Updated: 2024/02/15 11:35:57 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"


static void	ft_think(t_philo *philo)
{
	size_t	time;
	
	philo->state = THINK;
	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	printf("%zu %d is thinking\n", time, (philo->id));
	pthread_mutex_unlock(philo->write_lock);
}

static void	ft_eat(t_philo *philo)
{
	size_t	time;
	
	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	philo->state = EAT;
	philo->meals_eaten++;
	pthread_mutex_lock(philo->write_lock);
	printf("%zu %d is eating\n", time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
	philo->last_meal = get_time();
	ft_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static void	ft_sleep(t_philo *philo)
{
	size_t	time;
	
	philo->state = SLEEP;
	time = get_time() - philo->start_time;
	pthread_mutex_lock(philo->write_lock);
	printf("%zu %d is sleeping\n", time, philo->id);
	pthread_mutex_unlock(philo->write_lock);
	ft_usleep(philo->time_to_sleep);
}

static void	ft_die(t_philo *philo)
{
	size_t	time;
	
	time = get_time() - philo->start_time;
	if (time - philo->last_meal > philo->time_to_die)
		{
			pthread_mutex_lock(philo->dead_lock);
			*(philo->dead_flag) = 1;
			pthread_mutex_unlock(philo->dead_lock);
		}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	ft_think(philo);
	ft_die(philo);
	ft_eat(philo);
	ft_sleep(philo);
	return (NULL);
}