/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:57:57 by gsims             #+#    #+#             */
/*   Updated: 2024/02/20 14:38:06 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	conditions(const char c)
{
	if (c == '-' || c == '+')
		return (2);
	else if (c >= 9 && c <= 13)
		return (1);
	else if (c == 32)
		return (1);
	else if (ft_isdigit(c) == 1)
		return (3);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	if (conditions(*str) == 0)
		return (0);
	while (conditions(*str) == 1)
		str++;
	if (conditions(*str) == 2)
	{
		if (conditions(*(str + 1)) != 3)
			return (0);
		else if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

// Print function for philosophers
void	print_philo(t_philo *philo, char *message)
{
	int		colour_index;
	char 	*colour;

	colour_index = philo->id % 5;
	colour = philo->colours[colour_index];
	pthread_mutex_lock(philo->dead_lock);
	if (*(philo->dead_flag) == 1)
		colour = philo->colours[5];
	pthread_mutex_unlock(philo->dead_lock);
	pthread_mutex_lock(philo->write_lock);
	printf("%s%zu %d %s%s\n", colour, get_time_start(philo->start_time), philo->id, message, RESET_COLOUR);
	pthread_mutex_unlock(philo->write_lock);
}

// test to see if threads should stop immediately (dead philo or meals eaten)
int	stop_threads(t_philo *philo)
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