/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   philo.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 10:21:54 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/03 15:40:51 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>        // for printf
# include <stdlib.h>       // for malloc, free, and exit
# include <string.h>       // for memset
# include <unistd.h>       // for usleep and write
# include <sys/time.h>     // for gettimeofday
# include <pthread.h>      // for pthread & mutex

typedef struct s_data{
	int					philo_nr;
	int					meal_nbr;
	int					done;
	int					status;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	pthread_mutex_t		*forks;
}	t_data;

typedef struct s_philo{
	int					id;
	int					meals_eaten;
	unsigned long		last_meal;
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*print;
	t_data				*data;

}	t_philo;


#endif