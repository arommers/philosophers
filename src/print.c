/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 10:39:50 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/05 10:58:56 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(t_philo *philo, char *msg, int i)
{
	unsigned long	time;

	time = get_time() - philo->data->start;
	pthread_mutex_lock(philo->data->print);
	if (philo->data->status == 0)
	{
		if (i == 0)
			printf("\033[1;32m%lu %d %s\033[0m\n", time, philo->id, msg);
		else if (i == 1)
			printf("\033[1;33m%lu %d %s\033[0m\n", time, philo->id, msg);
		else if (i == 2)
			printf("\033[1;31;5m%lu %d %s\033[0m\n", time, philo->id, msg);
		else if (i == 3)
			printf("\033[1;95m%lu %d %s\033[0m\n", time, philo->id, msg);
		else
			printf("\033[1;36m%lu %d %s\033[0m\n", time, philo->id, msg);
		pthread_mutex_unlock(philo->data->print);
	}
	else
		pthread_mutex_unlock(philo->data->print);
}
