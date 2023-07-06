/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 15:30:45 by arommers      #+#    #+#                 */
/*   Updated: 2023/07/06 14:40:35 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Verifies whether one of the philosophers has died.

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(philo->data->public);
	if (philo->data->status == DEAD)
	{
		pthread_mutex_unlock(philo->data->public);
		return (TRUE);
	}
	else
		pthread_mutex_unlock(philo->data->public);
	return (FALSE);
}

// Verifies if a specific philo is done eating
// and adjusts the done variable if indeed true.

int	done_check(t_philo *philo)
{
	pthread_mutex_lock(philo->data->finished);
	if (philo->meals_eaten == philo->data->meal_nbr)
	{
		philo->data->done++;
		pthread_mutex_unlock(philo->data->finished);
		return (TRUE);
	}
	pthread_mutex_unlock(philo->data->finished);
	return (FALSE);
}

// converts a string to an unsigned long integer.

unsigned long	ft_atolong(char *str)
{
	int				i;
	unsigned long	val;

	i = 0;
	val = 0;
	while (str[i] == '\t' || str[i] == '\f' || str[i] == ' '
		|| str[i] == '\v' || str[i] == '\n' || str[i] == '\r')
		i++;
	while (str[i])
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	return (val);
}

// Get time in milliseconds

unsigned long	get_time(void)
{
	struct timeval	tv;
	unsigned long	time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

// A more precise sleep function 
// by incorporating intervals with an additional delay within the loop.

void	exact_sleep(unsigned long time)
{
	unsigned long	start;
	unsigned long	end;
	unsigned long	current;

	start = get_time();
	end = start + time;
	while (1)
	{
		current = get_time();
		if (current >= end)
			break ;
		else
			usleep(500);
	}
}
