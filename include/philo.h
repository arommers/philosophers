/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 10:21:54 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/29 11:41:13 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>     // for printf
# include <stdlib.h>    // for malloc, free, and exit
# include <unistd.h>    // for usleep and write
# include <sys/time.h>  // for gettimeofday
# include <pthread.h>   // for pthread & mutex
# include <stdbool.h>	// for bool
# include <limits.h>	// for atol

typedef enum e_status {
	ALIVE,
	DEAD,
}	t_status;

typedef struct s_data {
	unsigned long		start;
	int					nr_philos;
	int					meal_nbr;
	int					done;
	int					status;
	int					who_died;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*print;
}	t_data;

typedef struct s_philo {
	int					id;
	int					meals_eaten;
	unsigned long		last_meal;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	t_data				*data;
}	t_philo;

// typedef struct s_fork {
// 	pthread_mutex_t mutex;
//	bool			taken;
// }	t_fork;

//	Simulate functions

void	*run_sim(void *arg);
int		simulate(t_data *data, t_philo *philos);
int		philo_threads(pthread_t *threads, t_data *data, t_philo *philos);

//	Initialize functions

int		init_forks(t_data *data);
int		init_philos(t_data *data, t_philo *philos);
int		init_data(int argc, char **argv, t_data *data);
int		initialize(int argc, char **argv, t_data **data, t_philo **philos);

//	Utility functions

unsigned long	get_time(void);
unsigned long	ft_atolong(char *str);
void			print_msg(t_philo *philo, char *msg);

#endif