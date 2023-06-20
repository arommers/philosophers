/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 15:09:07 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/20 21:13:10 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Initializes the forks in the data structure.

int	init_forks(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(data->nr_philos * sizeof(pthread_mutex_t));
	if (!data->forks)
		return (data_error("Malloc failed", data));
	while (i < data->nr_philos)
		pthread_mutex_init(&data->forks[i++], NULL);
	return (SUCCESS);
}

// Initializes the data structure with values obtained from the command-line arguments.

int	init_data(int argc, char **argv, t_data *data)
{
	data->nr_philos = (int)ft_atolong(argv[1]);
	data->time_to_die = (int)ft_atolong(argv[2]);
	data->time_to_eat = (int)ft_atolong(argv[3]);
	data->time_to_sleep = (int)ft_atolong(argv[4]);
	if (argc == 6)
		data->meal_nbr = (int)ft_atolong(argv[5]);
	else
		data->meal_nbr = -1;
	data->done = 0;
	data->status = ALIVE;
	if (init_forks(data) == FAIL)
		return (FAIL);
	data->finished = malloc(sizeof(pthread_mutex_t));
	if (!data->finished)
		return (data_error("Malloc failed", data));
	data->public = malloc(sizeof(pthread_mutex_t));
	if (!data->public)
		return (data_error("Malloc failed", data));
	pthread_mutex_init(data->finished, NULL);
	pthread_mutex_init(data->public, NULL);
	return (SUCCESS);
}

// Initializes the philos array of t_philo structures.

int	init_philos(t_data *data, t_philo *philos)
{
	int				i;
	pthread_mutex_t	*private;

	private = malloc(data->nr_philos * sizeof(pthread_mutex_t));
	if (!private)
		return (print_error("Malloc failed\n", philos));
	i = 0;
	while (i < data->nr_philos)
	{
		philos[i].id = i + 1;
		philos[i].meals_eaten = 0;
		philos[i].last_meal = get_time();
		philos[i].l_fork = &data->forks[i];
		philos[i].r_fork = &data->forks[(i + 1) % data->nr_philos];
		pthread_mutex_init(&private[i], NULL);
		philos[i].private = &private[i];
		philos[i].data = data;
		i++;
	}
	return (SUCCESS);
}

// Initializes the data and philos structures.

int	init(int argc, char **argv, t_data **data, t_philo **philos)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
	{
		printf("Malloc failed");
		return (FAIL);
	}
	if (init_data(argc, argv, *data) == FAIL)
		return (FAIL);
	*philos = malloc(sizeof(t_philo) * (*data)->nr_philos);
	if (!*philos)
		return (data_error("Malloc failed\n", *data));
	if (init_philos(*data, *philos) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
