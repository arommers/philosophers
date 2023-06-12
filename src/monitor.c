/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   monitor.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: adri <adri@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/12 08:46:16 by adri          #+#    #+#                 */
/*   Updated: 2023/06/12 14:01:47 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*observe(void *arg)
{
	int				i;
	t_philo			*philos;
	unsigned long	meal;

	philos = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < philos->data->nr_philos)
		{
			pthread_mutex_lock(philos[i].eating);
			meal = philos[i].last_meal;
			if ((get_time() - meal) >= (unsigned long)philos[i].data->time_to_die
				&& philos[i].meals_eaten != philos[i].data->meal_nbr)
			{
				pthread_mutex_unlock(philos[i].eating);
				print_msg(&philos[i], "has died", 2);
				pthread_mutex_lock(philos[i].data->print);
				philos[i].data->status = DEAD;
				pthread_mutex_unlock(philos[i].data->print);
				return ((void *) 0);
			}
			pthread_mutex_unlock(philos[i].eating);
			i++;
		}
		pthread_mutex_lock(philos->data->print);
		if (philos->data->done >= philos->data->nr_philos)
		{
			pthread_mutex_unlock(philos->data->print);
			return ((void *) 0);
		}
		pthread_mutex_unlock(philos->data->print);
		exact_sleep(philos->data->time_to_die);
	}
	return ((void *) 0);
}

int	run_monitor(t_philo *philos, pthread_t *monitor)
{
	if (pthread_create(monitor, NULL, &observe, philos) != SUCCESS)
		return (print_error("Creating threads failed\n", philos));
	return (SUCCESS);
}