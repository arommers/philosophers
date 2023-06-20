/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: adri <adri@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 08:46:16 by adri          #+#    #+#                 */
/*   Updated: 2023/06/20 21:25:55 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Monitor checks if a philospher has died

int	monitor_dead(t_philo *philo)
{
	unsigned long	meal;
	
	pthread_mutex_lock(philo->private);
	meal = philo->last_meal;
	if ((get_time() - meal) >= (unsigned long)philo->data->time_to_die
			&& philo->meals_eaten != philo->data->meal_nbr)
	{
		pthread_mutex_unlock(philo->private);
		print_msg(philo, "has died", 2);
		pthread_mutex_lock(philo->data->public);
		philo->data->status = DEAD;
		pthread_mutex_unlock(philo->data->public);
		return (TRUE);
	}
	pthread_mutex_unlock(philo->private);
	return (FALSE);
}

// Checks if all philosphers are done eating

int	monitor_done(t_philo *philos)
{
	int		finished;
	int		goal;
	
	pthread_mutex_lock(philos->data->finished);
	finished = philos->data->done;
	goal = philos->data->nr_philos;
	pthread_mutex_unlock(philos->data->finished);
	if (finished >= goal)
		return (TRUE);
	return (FALSE);
}

// Represents the behavior of a monitoring thread.

void	*observe(void *arg)
{
	int		i;
	t_philo	*philos;
	// unsigned long	meal;

	philos = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philos->data->nr_philos)
		{
			if (monitor_dead(&philos[i]) == TRUE)
				return ((void *) 0);
			// pthread_mutex_lock(philos[i].private);
			// meal = philos[i].last_meal;
			// if ((get_time() - meal) >= (unsigned long)philos[i].data->time_to_die
			// 	&& philos[i].meals_eaten != philos[i].data->meal_nbr)
			// {
			// 	pthread_mutex_unlock(philos[i].private);
			// 	print_msg(&philos[i], "has died", 2);
			// 	pthread_mutex_lock(philos[i].data->public);
			// 	philos[i].data->status = DEAD;
			// 	pthread_mutex_unlock(philos[i].data->public);
			// 	return ((void *) 0);
			// }
			// pthread_mutex_unlock(philos[i].private);
			i++;
		}
		if (monitor_done(philos) == TRUE)
			return ((void *) 0);
		// pthread_mutex_lock(philos->data->public);
		// if (philos->data->done >= philos->data->nr_philos)
		// {
		// 	pthread_mutex_unlock(philos->data->public);
		// 	return ((void *) 0);
		// }
		// pthread_mutex_unlock(philos->data->public);
		exact_sleep(philos->data->time_to_die);
	}
	return ((void *) 0);
}

// Create the monitor thread and start the observe function.

int	run_monitor(t_philo *philos, pthread_t *monitor)
{
	if (pthread_create(monitor, NULL, &observe, philos) != SUCCESS)
		return (print_error("Creating threads failed\n", philos));
	return (SUCCESS);
}