/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 10:39:50 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/31 15:09:30 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, char *msg, int i)
{
	unsigned long	time;

	time = get_time() - philo->data->start;
	pthread_mutex_lock(philo->data->print);
	if (i == 0)
		printf("\033[1;32m%lu %d %s\033[0m\n", time, philo->id, msg);
	else if (i == 1)
		printf("\033[1;33m%lu %d %s\033[0m\n", time, philo->id, msg);
	else
		printf("\033[1;31;5m%lu %d %s\033[0m\n", time, philo->id, msg);
	pthread_mutex_unlock(philo->data->print);
}

void	print_sleep(t_philo *philo)
{
	unsigned long	time;

	time = get_time() - philo->data->start;
	pthread_mutex_lock(philo->data->print);
	printf("\033[1;95m%lu %d is sleeping\033[0m\n", time, philo->id);
	pthread_mutex_unlock(philo->data->print);
}

void	print_think(t_philo *philo)
{
	unsigned long	time;

	time = get_time() - philo->data->start;
	pthread_mutex_lock(philo->data->print);
	printf("\033[1;36m%lu %d is thinking\033[0m\n", time, philo->id);
	pthread_mutex_unlock(philo->data->print);
}
