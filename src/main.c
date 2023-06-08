/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 15:01:37 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/08 22:52:58 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philos;

	data = NULL;
	philos = NULL;
	if (input_check(argc, argv) != 0)
		return (1);
	if (init(argc, argv, &data, &philos) != 0)
		return (1);
	if (data->nr_philos == 1)
	{
		solo_philo(data, philos);
		return (0);
	}
	if (simulate(data, philos) != 0)
		return (1);
	if (data->done == data->nr_philos)
		printf("%lu all philos are done eating\n", get_time() - data->start);
	return (0);
}
