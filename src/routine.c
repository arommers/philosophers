/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   routine.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/29 12:47:33 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/29 13:15:58 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	print_msg(philo, "has taken a fork");
	pthread_mutex_lock(philo->r_fork);
	print_msg(philo, "has taken a fork");
	print_msg(philo, "is eating");
	usleep(philo->data->time_to_die);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	usleep(philo->data->time_to_sleep);
	print_msg(philo, "is sleeping");
}

int	routine(t_philo *philo)
{
	take_forks(philo);
	philo->last_meal = get_time();
	philo->meals_eaten++;
	drop_forks(philo);
	return (1);
}
