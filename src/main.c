/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 15:01:37 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/12 13:40:47 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_leaks(void)
{
	system("leaks -q philo");
}


int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo	*philos;

	data = NULL;
	philos = NULL;
	// atexit(check_leaks);
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
