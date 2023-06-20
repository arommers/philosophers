/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   threads.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 12:43:21 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/20 21:20:49 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// The entry point for the philosopher threads. 
// It performs a continuous loop where it checks for
// the philosopher's death, completion of meals,
// and executes the routine of actions for the philosopher.

void	*run_sim(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		exact_sleep(philo->data->time_to_eat / 10);
	while (1)
	{
		if (dead_check(philo) == TRUE)
			return ((void *) 0);
		if (done_check(philo) == TRUE)
			return ((void *) 0);
		routine(philo);
	}
	return ((void *) 0);
}

	// Creates multiple a thread for each philosopher, runs a monitoring thread,
	// waits for all philosopher threads to finish, and then detaches the monitoring thread.

int	run_threads(pthread_t *threads, t_data *data, t_philo *philos)
{
	int			i;
	pthread_t	monitor;

	i = -1;
	data->start = get_time();
	while (++i < data->nr_philos)
	{
		if (pthread_create(&threads[i], NULL, &run_sim, &philos[i]) != SUCCESS)
			return (print_error("Creating threads failed\n", philos));
	}
	if (run_monitor(philos, &monitor) != SUCCESS)
		return (FAIL);
	while (--i >= 0)
	{
		if (pthread_join(threads[i], NULL) != SUCCESS)
			return (print_error("Joining threads failed\n", philos));
	}
	pthread_detach(monitor);
	return (SUCCESS);
}

//  Simulates the dining philosophers problem
//	by creating and running a thread for each individual philosopher.

int	simulate(t_data *data, t_philo *philos)
{
	pthread_t	*threads;

	threads = malloc((data->nr_philos + 1) * sizeof(pthread_t));
	if (!threads)
		return (print_error("Malloc failed\n", philos));
	if (run_threads(threads, data, philos) == FAIL)
		return (FAIL);
	free (threads);
	return (SUCCESS);
}
