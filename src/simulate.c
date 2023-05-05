/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 12:43:21 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/05 15:10:39 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*run_sim(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	take_fork(philos);
	eat();
	drop_fork();
	return (NULL);
}

int	philo_threads(pthread_t *threads, t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->nr_philos)
	{
		if (pthread_create(&threads[i], 0, &run_sim, (void *)&philos[i]) != 0)
		{
			//error_message
			return (1);
		}
		i++;
	}
	while (i >= 0)
	{
		if (pthread_join(threads[i], 0) != 0)
		{
			//error message
			return(1);
		}
	}
	return (0);
}

int	simulate(t_data *data, t_philo *philos)
{
	pthread_t	*threads;

	threads = malloc(data->nr_philos * sizeof(pthread_t));
	if (!threads)
	{
		// free stuff
		// error message
		return (1);
	}
	if (philo_threads(threads, data, philos) != 0)
	{
		// free stuff
		return (1);
	}
	if (monitor(data, philos) != 0)
	{
		// free stuff
		// error message
		return (1);
	}
	free (threads);
	check_sim_status(data, philos);
	return (0);
}
