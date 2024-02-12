/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:37:36 by gsims             #+#    #+#             */
/*   Updated: 2024/02/12 16:02:13 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


typedef enum {
	THINK,
	EAT,
	SLEEP,
}	e_state;

typedef struct	s_philo {
	int					id;
	int					state;
	int					meals_eaten;
	size_t				last_meal;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	size_t				start_time;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*dead_lock;
	pthread_mutex_t		*meal_lock;
}						t_philo;


typedef	struct s_data {
	int					number_of_philosophers;
	int					time_to_die;
	int					time_to_eat; 
	int					time_to_sleep; // sleep time in milliseconds
	int					number_of_times_each_philosopher_must_eat;
	int					dead_flag; // when = 1 means a philo died
	pthread_mutex_t		dead_lock; // mutex for accessing the dead_flag
	pthread_mutex_t		meal_lock; // mutex for eating
	pthread_mutex_t		write_lock; // mutex for writing into the CLI 
	t_philo				*philo;	
}						t_data;


int			input_check(int ac, char *av[]);
int			ft_isdigit(char c);
int			ft_atoi(const char	*str);
int			init_data(t_data *d, char *av[]);
size_t		get_current_time(void);

#endif