/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 10:39:50 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/31 10:48:45 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_eat(t_philo *philo, char *msg)
{
	unsigned long	time;

	time = get_time() - philo->data->start;
	pthread_mutex_lock(philo->data->print);
	printf("\033[1;32m%lu %d %s\033[0m\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->data->print);
}

void	print_sleep(t_philo *philo, char *msg)
{
	unsigned long	time;

	time = get_time() - philo->data->start;
	pthread_mutex_lock(philo->data->print);
	printf("\033[1;95m%lu %d %s\033[0m\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->data->print);
}

void	print_think(t_philo *philo, char *msg)
{
	unsigned long	time;

	time = get_time() - philo->data->start;
	pthread_mutex_lock(philo->data->print);
	printf("\033[1;46m%lu %d %s\033[0m\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->data->print);
}
