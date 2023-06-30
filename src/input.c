/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: adri <adri@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/08 17:41:19 by adri          #+#    #+#                 */
/*   Updated: 2023/06/28 11:42:28 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Checks if a character is a digit

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

// Verifies if each command line argument falls between 0 to INT_MAX

int	size_check(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_atolong(argv[i]) < 0 || ft_atolong(argv[i]) > INT_MAX)
			return (FALSE);
	}
	return (TRUE);
}

// Verifies if all the characters in command line arguments are digits

int	digit_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) != TRUE)
				return (FALSE);
			j++;
		}
	}
	return (TRUE);
}

// Run a simulation for a single philosopher

void	solo_philo(t_data *data, t_philo *philo)
{
	pthread_t	thread;
	pthread_t	monitor;

	data->start = get_time();
	if (pthread_create(&thread, NULL, &run_sim, &philo[0]) != SUCCESS)
		print_error("Creating threads failed", philo);
	run_monitor(philo, &monitor);
	exact_sleep(data->time_to_die + 10);
	pthread_detach(monitor);
	pthread_detach(thread);
	ft_clean(philo);
}

// Validates the input arguments

int	input_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (FALSE);
	if (ft_atolong(argv[1]) > 200)
		return (FALSE);
	if (size_check(argc, argv) != TRUE)
		return (FALSE);
	if (digit_check(argc, argv) != TRUE)
		return (FALSE);
	return (SUCCESS);
}
