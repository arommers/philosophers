/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   practice.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 13:28:30 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/01 13:21:11 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
    int k;
    int index;
    int sum;

	index = *(int*)arg;
    sum = 0;
    k = 0;
    while (k < 5)
    {
		sum	+= primes[index + k];
		k++;
    }
	*(int *)arg = sum;
	return (arg);
}

int	main(int argc, char **argv)
{
	int			i;
	int			j;
	int			*a;
	void		*result;
	int			globalsum;
	pthread_t	thread[2];

	i = 0;
	j = 0;
	globalsum = 0;
	while (i < 2)
	{
		a = malloc(sizeof(int));
		if (!a)
			perror("malloc");
		*a = i * 5;
		if (pthread_create(&thread[i], NULL, &routine, a) != 0)
			perror("ERROR 1");
		i++;
	}
	while (j < 2)
	{
		if (pthread_join(thread[j], (void **)&result) != 0)
			perror("ERROR 2");
		globalsum += *(int *)result;
		free(result);
		j++;
	}
	printf("GS: %d\n", globalsum);
	return (0);
}
