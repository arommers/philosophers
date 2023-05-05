/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 15:09:07 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/05 15:49:20 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->nr_philos * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (1);
	while (i < data->nr_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
	return (0);
}

int	init_data(int argc, char **argv, t_data *data)
{
	data->nr_philos = (int)atolong(argv[1]);
	data->time_to_die = (int)atolong(argv[2]);
	data->time_to_eat = (int)atolong(argv[3]);
	data->time_to_sleep = (int)atolong(argv[4]);
	if (argc == 6)
		data->meal_nbr = (int)atolong(argv[5]);
	else
		data->meal_nbr = -1;
	data->done = 0;
	data->status = ALIVE;
	data->who_died = 0;
	if (init_forks(data) != 0)
		return (1);
	return (0);
}

int	init_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = 0;
	while (i < data->nr_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = get_time();
		philos[i].l_fork = &data->forks[i];
		philos[i].r_fork = &data->forks[(i + 1) % data->nr_philos];
		philos[i].print = NULL;
		philos[i].data = data;
	}
}

int	initialize(int argc, char **argv, t_data *data, t_philo	*philos)
{
	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
	{
		error_msg("msg");
		return (1);
	}
	if (init_data(argc, argv, data) != 0) // you allocate here!!
	{
		// free data struct
	}
	philos = (t_philo *)malloc(sizeof(t_philo) * data->nr_philos);
	if (!philos)
	{
		// free data struct;
		error_msg("msg");
		return (1);
	}
	if (init_philos(data, philos) != 0)
	{
		// free data struct;
		return (1);
	}
	return (0);
}
