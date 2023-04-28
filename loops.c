/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loops.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 15:24:26 by arommers      #+#    #+#                 */
/*   Updated: 2023/04/28 15:39:57 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	int	i;

	i = 0;
	pthread_mutex_lock(&mutex);
	while (i < 1000000)
	{
		mails++;
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	thread[8];
	int			i;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 8)
	{
		if (pthread_create(&thread[i], NULL, &routine, NULL) != 0)
		{
			perror("ERROR");
			return (1);
		}
		printf("thread %d has started\n", i);
		i++;
	}
	i = 0;
	while (i < 8)
	{
		if (pthread_join(thread[i], NULL) != 0)
		{
			perror("ERROR");
			return (2);
		}
		printf("thread %d is done\n", i);
		i++;
	}
	pthread_mutex_destroy(&mutex);
	printf("mails: %d\n", mails);
	return (0);
}
