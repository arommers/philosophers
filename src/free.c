/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/09 12:13:04 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/09 15:20:25 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_mutex(t_philo *philo)
{
	int	i;

	i = -1;
	while (++i < philo->data->nr_philos)
	{
		pthread_mutex_destroy(&philo->data->forks[i]);
		pthread_mutex_destroy(philo[i].eating);
	}
	pthread_mutex_destroy(philo->data->print);
}


void	ft_clean(t_philo *philo)
{
	if (philo->data)
	{
		clean_mutex(philo);
		if (philo->data->forks)
			free(philo->data->forks);
		if (philo->data->print)
			free(philo->data->print);
		if (philo->eating)
			free(philo->eating);
		free(philo->data);
	}
	free (philo);
}
