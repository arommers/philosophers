/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/05 11:41:16 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/05 11:41:43 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	spacecheck(char c)
{
	if (c == '\t' || c == '\f' || c == ' '
		|| c == '\v' || c == '\n' || c == '\r')
		return (1);
	return (0);
}

int	digit_check(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	size_check(int val, int min)
{
	if (min == 1)
	{
		if (val > INT_MAX)
			val = INT_MAX;
	}
	if (min == -1)
	{
		val = val * min;
		if (val < INT_MIN)
			val = INT_MIN;
	}
	return (val);
}

int	ft_atoi(char *str)
{
	int	i;
	int	min;
	int	val;

	i = 0;
	min = 1;
	val = 0;
	while (space_check(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	while (digit_check(str[i]))
	{
		val = val * 10 + (str[i] - '0');
		i++;
	}
	size_check(val, min);
	return (val);
}
