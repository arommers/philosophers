/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   passing_args.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 13:28:30 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/01 12:17:54 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int index;

	index = *(int*)arg;
	printf("%d ", primes[index]);
	free(arg);
	return (NULL);
}

int	main(int argc, char **argv)
{
	int			i;
	int			j;
	int			*a;
	pthread_t	thread[10];

	i = 0;
	j = 0;
	while (i < 10)
	{
		a = malloc(sizeof(int));
		if (!a)
			perror("malloc");
		*a = i;
		if (pthread_create(&thread[i], NULL, &routine, a) != 0)
			perror("ERROR 1");
		i++;
	}
	while (j < 10)
	{
		if (pthread_join(thread[j], NULL) != 0)
			perror("ERROR 2");
		j++;
	}
	return (0);
}
