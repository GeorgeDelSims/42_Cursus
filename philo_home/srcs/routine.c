/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:53:04 by gsims             #+#    #+#             */
/*   Updated: 2024/02/13 13:29:22 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;	
	pthread_mutex_lock(philo->write_lock);
	printf("%d is thinking\n", philo->id);
	philo->state = THINK;
	pthread_mutex_unlock(philo->write_lock);
	pthread_mutex_lock(philo->l_fork);
	pthread_mutex_lock(philo->r_fork);
	pthread_mutex_lock(philo->write_lock);
	printf("%d is eating\n", philo->id);
	philo->state = EAT;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->write_lock);
	pthread_mutex_lock(philo->write_lock);
	printf("%d is sleeping\n", philo->id);
	philo->state = SLEEP;
	pthread_mutex_unlock(philo->write_lock);
	return (NULL);
}