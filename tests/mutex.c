/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mutex.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 14:46:35 by arommers      #+#    #+#                 */
/*   Updated: 2023/04/26 15:41:56 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	int	i;

	i = 0;
	pthread_mutex_lock(&mutex);
	while (i < 100000000)
	{
		mails++;
		// read mails
		// increment
		// write mails
		i++;
	}
	pthread_mutex_unlock(&mutex);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;
	pthread_t	t3;
	pthread_t	t4;

	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		perror("ERROR1\n");
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		perror("ERROR2\n");
	if (pthread_create(&t3, NULL, &routine, NULL) != 0)
		perror("ERROR5\n");
	if (pthread_create(&t4, NULL, &routine, NULL) != 0)
		perror("ERROR6\n");
	if (pthread_join(t1, NULL) != 0)
		perror("ERROR3\n");
	if (pthread_join(t2, NULL) != 0)
		perror("ERROR4\n");
	if (pthread_join(t3, NULL) != 0)
		perror("ERROR7\n");
	if (pthread_join(t4, NULL) != 0)
		perror("ERROR8\n");
	pthread_mutex_destroy(&mutex);
	printf("mails: %d\n", mails);
	return (0);
}
