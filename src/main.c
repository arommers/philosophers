/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 15:01:37 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/30 12:08:22 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philos;

	data = NULL;
	philos = NULL;
	if (input_check(argc, argv) == FALSE)
	{
		printf("Invalid input\n");
		return (FAIL);
	}
	if (init(argc, argv, &data, &philos) == FAIL)
		return (FAIL);
	if (data->nr_philos == 1)
	{
		solo_philo(data, philos);
		return (SUCCESS);
	}
	if (simulate(data, philos) == FAIL)
		return (FAIL);
	if (data->done == data->nr_philos)
		printf("\033[1;32m%lu all philos are done eating\033[0m\n",
			get_time() - data->start);
	ft_clean(philos);
	return (SUCCESS);
}
