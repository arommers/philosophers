/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 12:47:33 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/20 21:22:32 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Pick up forks and start eating

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg(philo, "has taken a fork", 1);
	pthread_mutex_lock(philo->l_fork);
	print_msg(philo, "has taken a fork", 1);
	print_msg(philo, "is eating", 0);
}

// Put down the forks, sleep and think

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	print_msg(philo, "is sleeping", 3);
	exact_sleep(philo->data->time_to_sleep);
	print_msg(philo, "is thinking", 4);
}

// Represents the sequence of actions performed by a philosopher
// during their turn in the simulation

void	routine(t_philo *philo)
{
	take_forks(philo);
	pthread_mutex_lock(philo->private);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->private);
	exact_sleep(philo->data->time_to_eat);
	drop_forks(philo);
}
