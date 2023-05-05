/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/03 15:30:45 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/05 12:38:29 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_atolong(char *str)
{
	int				i;
	int				sign;
	unsigned long	val;

	i = 0;
	sign = 1;
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
