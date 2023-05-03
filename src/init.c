/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 15:09:07 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/03 16:03:07 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_data(int argc, char **argv, t_data *data)
{
	data->philo_nr = (int)atolong(argv[1]);
	data->time_to_die = atolong(argv[2]);
	data->time_to_eat = atolong(argv[3]);
	data->time_to_sleep = atolong(argv[4]);
	if (argc == 6)
		data->meal_nbr = (int)atolong(argv[5]);
	else
		data->meal_nbr = -1;
	data->done = 0;
	data->status = 0;
	if (init_forks(data) != 0)
		return (1);
	return (0);
}

int	init_philos(t_data *data, t_philo *philos)
{
	int	i;

	i = 1;
	while (i < data->philo_nr)
	{
		philos->id = i;
		philos->data = data;
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
	init_data(argc, argv, data);
	philos = (t_philo *)malloc(sizeof(t_philo) * data->philo_nr);
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
