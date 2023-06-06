/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 15:01:37 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/06 22:13:12 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philos;

	data = NULL;
	philos = NULL;
	// if (input_check(argc, argv != 0))
	// 	return (1);
	if (init(argc, argv, &data, &philos) != 0)
		return (1);
	if (simulate(data, philos) != 0)
		return (1);
	if (data->done == data->nr_philos)
		print_msg(philos, "all are done eating", 5);
	return (0);
}
