/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 10:21:54 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/12 13:38:33 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>     // for printf
# include <stdlib.h>    // for malloc, free, and exit
# include <unistd.h>    // for usleep and write
# include <sys/time.h>  // for gettimeofday
# include <pthread.h>   // for pthread & mutex
# include <limits.h>	// for atolong and input check

// Defines for readability

# define ALIVE 0
# define DEAD 1

# define SUCCESS 0
# define FAIL 1

# define TRUE 0
# define FALSE 1

// Structs

typedef struct s_data {
	unsigned long		start;
	int					nr_philos;
	int					meal_nbr;
	int					done;
	int					status;
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
	pthread_mutex_t		*eating;
	t_data				*data;
}	t_philo;

//	Thread functions

void			*observe(void *arg);
void			*run_sim(void *arg);
int				simulate(t_data *data, t_philo *philos);
int				run_monitor(t_philo *philos, pthread_t *monitor);
int				run_threads(pthread_t *threads, t_data *data, t_philo *philos);

//	routine

void			routine(t_philo *philo);
void			take_forks(t_philo *philo);
void			drop_forks(t_philo *philo);

//	Initialize functions

int				init_forks(t_data *data);
int				init_philos(t_data *data, t_philo *philos);
int				init_data(int argc, char **argv, t_data *data);
int				init(int argc, char **argv, t_data **data, t_philo **philos);

// Input Check functions

int				ft_isdigit(char c);
int				size_check(int argc, char **argv);
int				digit_check(int argc, char **argv);
int				input_check(int argc, char **argv);
int				solo_philo(t_data *data, t_philo *philo);


//	Utility functions

unsigned long	get_time(void);
unsigned long	ft_atolong(char *str);
int				dead_check(t_philo *philo);
int				done_check(t_philo *philo);
void			exact_sleep(unsigned long time);
int				print_error(char *msg, t_philo *philo);
void			print_msg(t_philo *philo, char *msg, int i);

// Clean functions

void			ft_clean(t_philo *philo);
void			clean_mutex(t_philo *philo);
int				data_error(char *msg, t_data *data);

#endif