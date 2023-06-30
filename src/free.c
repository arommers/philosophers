/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/09 12:13:04 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/30 12:00:04 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Destroy mutexes

void	clean_mutex(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->nr_philos)
	{
		pthread_mutex_destroy(&philo->data->forks[i]);
		pthread_mutex_destroy(philo[i].private);
	}
	pthread_mutex_destroy(philo->data->public);
	pthread_mutex_destroy(philo->data->finished);
}

// Destroy mutexes and free all allocated memory

void	ft_clean(t_philo *philo)
{
	if (philo->data)
	{
		clean_mutex(philo);
		if (philo->data->forks)
			free(philo->data->forks);
		if (philo->data->public)
			free(philo->data->public);
		if (philo->data->finished)
			free(philo->data->finished);
		if (philo->private)
			free(philo->private);
		free(philo->data);
	}
	free (philo);
}
