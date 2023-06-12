/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 15:30:45 by arommers      #+#    #+#                 */
/*   Updated: 2023/06/12 13:58:15 by adri          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_check(t_philo *philo)
{
	pthread_mutex_lock(philo->data->print);
	if (philo->data->status == DEAD)
	{
		pthread_mutex_unlock(philo->data->print);
		return (TRUE);
	}
	else
		pthread_mutex_unlock(philo->data->print);
	return (FALSE);
}

int	done_check(t_philo *philo)
{
	pthread_mutex_lock(philo->data->print);
	if (philo->meals_eaten == philo->data->meal_nbr)
	{
		philo->data->done++;
		pthread_mutex_unlock(philo->data->print);
		return (TRUE);
	}
	else
		pthread_mutex_unlock(philo->data->print);
	return (FALSE);
}

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

unsigned long	get_time(void)
{
	struct timeval	tv;
	unsigned long	time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (time);
}

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
