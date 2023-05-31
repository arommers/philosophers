/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 10:21:54 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/31 10:49:40 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>     // for printf
# include <stdlib.h>    // for malloc, free, and exit
# include <unistd.h>    // for usleep and write
# include <sys/time.h>  // for gettimeofday
# include <pthread.h>   // for pthread & mutex
# include <limits.h>	// for atolong

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
//	int				taken;
// }	t_fork;

//	Simulate functions

void			*run_sim(void *arg);
int				simulate(t_data *data, t_philo *philos);
int				run_threads(pthread_t *threads, t_data *data, t_philo *philos);

//	routine

void			take_forks(t_philo *philo);
void			drop_forks(t_philo *philo);
int				routine(t_philo *philo);

//	Initialize functions

int				init_forks(t_data *data);
int				init_philos(t_data *data, t_philo *philos);
int				init_data(int argc, char **argv, t_data *data);
int				init(int argc, char **argv, t_data **data, t_philo **philos);

//	Utility functions

unsigned long	get_time(void);
unsigned long	ft_atolong(char *str);
void			exact_sleep(unsigned long time);

// Print functions
void			print_eat(t_philo *philo, char *msg);
void			print_sleep(t_philo *philo, char *msg);
void			print_think(t_philo *philo, char *msg);

#endif