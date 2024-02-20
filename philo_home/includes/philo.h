/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsims <gsims@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 09:37:36 by gsims             #+#    #+#             */
/*   Updated: 2024/02/20 14:28:59 by gsims            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define RESET_COLOUR "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"

typedef struct s_philo
{
	char			**colours;
	pthread_t		thread_id;
	int				id;
	int				meals_eaten;
	int				*dead_flag;
	int				*meal_flag;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			*start_time;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_data
{
	char			*colours[6];
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_number;
	int				dead_flag;
	int				dead_philo_index;
	int				meal_flag;
	int				*threads;
	size_t			start_time;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
	t_philo			**philo;
	pthread_t		monitor_id;
}					t_data;

int					input_check(int ac, char *av[]);
int					ft_isdigit(char c);
int					ft_atoi(const char *str);
int					init_data(t_data *d, char *av[]);
int					philosophers(t_data *d);
int					ft_usleep(size_t milliseconds);
int					stop_threads(t_philo *philo);
void				*routine(void *arg);
void				*monitor(void *data);
void 				*dead_check(void *arg);
size_t				get_time(void);
size_t				get_time_start(size_t *pointer_to_start_time);
void				free_all(t_data *d);
void				print_philo(t_philo *philo, char *message);

#endif
