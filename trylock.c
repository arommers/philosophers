/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   trylock.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/01 13:36:14 by arommers      #+#    #+#                 */
/*   Updated: 2023/05/01 13:57:47 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>

pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	if (pthread_mutex_trylock(&mutex) == 0)
	{
		printf("got lock\n");
		sleep(1);
		pthread_mutex_unlock(&mutex);
	}
	else if (errno == EBUSY)
		printf("mutex is already locked\n");
	else
		printf("error locking mutex: %s\n", strerror(errno));
	return (NULL);
}

int	main(int argc, char *argv[])
{
	pthread_t	thread[4];
	int			i;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
			perror("ERROR1");
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(thread[i], NULL) != 0)
			perror("ERROR2");
		i++;
	}
	return (0);
}
