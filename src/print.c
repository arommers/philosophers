/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/31 10:39:50 by arommers      #+#    #+#                 */
/*   Updated: 2023/11/27 11:35:10 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Print error message and free all initialized in data

int	data_error(char *msg, t_data *data)
{
	int	i;

	i = -1;
	printf("%s\n", msg);
	if (data->forks)
	{
		while (++i < data->nr_philos)
			pthread_mutex_destroy(&data->forks[i]);
	}
	free(data);
	return (FAIL);
}

// Print an error message and free all allocated memory

int	print_error(char *msg, t_philo *philos)
{
	printf("%s\n", msg);
	ft_clean(philos);
	return (FAIL);
}

// Print a message according to the provided arguments

void	print_msg(t_philo *philo, char *msg, int i)
{
	unsigned long	time;

	time = get_time() - philo->data->start;
	pthread_mutex_lock(philo->data->public);
	if (philo->data->status == 0)
	{
		if (i == 0)
			printf("%lu %d %s\n", time, philo->id, msg);
		else if (i == 1)
			printf("%lu %d %s\n", time, philo->id, msg);
		else if (i == 2)
			printf("%lu %d %s\n", time, philo->id, msg);
		else if (i == 3)
			printf("%lu %d %s\n", time, philo->id, msg);
		else if (i == 4)
			printf("%lu %d %s\n", time, philo->id, msg);
		else
			printf("%lu %s\n", time, msg);
		// if (i == 0)
		// 	printf("\033[1;32m%lu %d %s\033[0m\n", time, philo->id, msg);
		// else if (i == 1)
		// 	printf("\033[1;33m%lu %d %s\033[0m\n", time, philo->id, msg);
		// else if (i == 2)
		// 	printf("\033[1;31m%lu %d %s\033[0m\n", time, philo->id, msg);
		// else if (i == 3)
		// 	printf("\033[1;95m%lu %d %s\033[0m\n", time, philo->id, msg);
		// else if (i == 4)
		// 	printf("\033[1;36m%lu %d %s\033[0m\n", time, philo->id, msg);
		// else
		// 	printf("\033[1;92m%lu %s\033[0m\n", time, msg);
		pthread_mutex_unlock(philo->data->public);
	}
	else
		pthread_mutex_unlock(philo->data->public);
}
