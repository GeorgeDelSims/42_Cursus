/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:53:04 by gsims             #+#    #+#             */
/*   Updated: 2024/02/26 17:01:00 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// increment mmeals_eaten + get time for last meal
static void	increment_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->meals_eaten.lock);
	philo->meals_eaten.value++;	
	pthread_mutex_unlock(&philo->meals_eaten.lock);
}

// updates the value of the last_meal variable
static void	update_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_meal.lock);
	philo->last_meal.value = get_time();
	pthread_mutex_unlock(&philo->last_meal.lock);	
}

// eat state main function
static void	ft_eat(t_philo *philo)
{	
	pthread_mutex_t *first_fork;
	pthread_mutex_t *second_fork;

	if (philo->l_fork_id < philo->r_fork_id)
	{
		first_fork = philo->l_fork;
		second_fork = philo->r_fork;
	} 
	else 
	{
		first_fork = philo->r_fork;
		second_fork = philo->l_fork;
	}
	pthread_mutex_lock(first_fork);
	print_philo(philo, "has taken a fork");
	pthread_mutex_lock(second_fork);	
	print_philo(philo, "has taken a fork");
	
	print_philo(philo, "is eating");
	update_last_meal(philo);
	ft_usleep(philo->time_to_eat);
	increment_meals(philo);
	//print_philo(philo, "has eaten");
	
	pthread_mutex_unlock(first_fork);
	//print_philo(philo, "has unlocked the first fork");
	pthread_mutex_unlock(second_fork);
	//print_philo(philo, "has unlocked the second fork");
}

// sleep function for the routine
static void	ft_sleep(t_philo *philo)
{
	print_philo(philo, "is sleeping");
	ft_usleep(philo->time_to_sleep);
	print_philo(philo, "has finished sleeping");
}

// Routine function 
void	*routine(void *arg)
{
	t_philo	*philo;
	int		even;
	
	philo = (t_philo *)arg;
	while (1)
	{
		even = philo->id % 2;
		print_philo(philo, "is thinking");
		if (even == 1)
			ft_eat(philo);	
		else 
		{
			usleep(200);
			ft_eat(philo);
		}
		ft_sleep(philo);
		//usleep(100);
		if (stop_threads(philo) == 1)
			break ;
	}
	return (NULL);
}
