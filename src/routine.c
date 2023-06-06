/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 12:47:33 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/06 08:46:59 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_msg(philo, "has taken a fork", 1);
	pthread_mutex_lock(philo->l_fork);
	print_msg(philo, "has taken a fork", 1);
	print_msg(philo, "is eating", 0);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	exact_sleep(philo->data->time_to_sleep);
	print_msg(philo, "is sleeping", 3);
}

int	routine(t_philo *philo)
{
	take_forks(philo);
	exact_sleep(philo->data->time_to_eat);
	pthread_mutex_lock(philo->eating);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->eating);
	drop_forks(philo);
	return (1);
}
