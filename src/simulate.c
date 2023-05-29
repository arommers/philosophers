/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 12:43:21 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/29 15:12:56 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*run_sim(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	print_msg(philo, "exists and is thinking");
	if (routine(philo) != 0)
	{
		// error_msg;
		return (1);
	}
	return (0);
}

int	run_threads(pthread_t *threads, t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->nr_philos)
	{
		if (pthread_create(&threads[i], 0, &run_sim, &philos[i]) != 0)
		{
			//error_message
			return (1);
		}
		i++;
	}
	--i;
	while (i >= 0)
	{
		if (pthread_join(threads[i], 0) != 0)
		{
			//error message
			return(1);
		}
		i--;
	}
	return (0);
}

int	simulate(t_data *data, t_philo *philos)
{
	pthread_t	*threads;

	threads = malloc((data->nr_philos + 1) * sizeof(pthread_t));
	if (!threads)
	{
		// free stuff
		// error message
		return (1);
	}
	if (run_threads(threads, data, philos) != 0)
	{
		// free stuff
		return (1);
	}
	// if (monitor(data, philos) != 0)
	// {
	// 	// free stuff
	// 	// error message
	// 	return (1);
	// }
	free (threads);
	// check_sim_status(data, philos);
	return (0);
}
