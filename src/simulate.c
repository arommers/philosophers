/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simulate.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 12:43:21 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/01 18:46:48 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*observe(void *arg)
{
	int				i;
	t_philo			*philos;
	unsigned long	meal;

	i = 0;
	philos = (t_philo *)arg;
	// exact_sleep(1000);
	while (1)
	{
		printf("test\n");
		meal = philos[i].last_meal;
		if ((get_time() - meal) >= (unsigned long)philos[i].data->time_to_die)
		{
			print_msg(&philos[i], "has died", 2);
			philos->data->status = 1;
			philos[i].data->who_died = philos[i].id;
			break ;
		}
		i = (i + 1) % philos[i].data->nr_philos;
	}
	return ((void *) 0);
}

void	*run_sim(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (dead_check(philo) == 1)
			break ;
		// if (done_check) == 0)
		// 	break ;
		if (routine(philo) != 1)
			break ;
		print_think(philo);
	}
	return ((void *) 0);
}

int	run_threads(pthread_t *threads, t_data *data, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < data->nr_philos)
	{
		if (pthread_create(&threads[i], NULL, &run_sim, &philos[i]) != 0)
		{
			//error_message
			return (1);
		}
		exact_sleep(1);
	}
	while (--i >= 0)
	{
		if (pthread_join(threads[i], NULL) != 0)
		{
			//error message
			return(1);
		}
	}
	return (0);
}

int	run_monitor(t_philo *philos)
{
	pthread_t	monitor;

	if (pthread_create(&monitor, NULL, &observe, &philos) != 0)
	{
		// free stuff
		return (1);
	}
	return (0);
}

int	simulate(t_data *data, t_philo *philos)
{
	pthread_t	*threads;

	threads = malloc((data->nr_philos + 1) * sizeof(pthread_t));
	if (!threads)
	{
		// error message
		return (1);
	}
	if (run_threads(threads, data, philos) != 0)
	{
		// free stuff
		return (1);
	}
	if (run_monitor(philos) != 0)
	{
		// free stuff
		return (1);
	}
	free (threads);
	// check_sim_status(data, philos);
	return (0);
}
