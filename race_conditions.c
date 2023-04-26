/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   race_conditions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/26 14:46:35 by arommers      #+#    #+#                 */
/*   Updated: 2023/04/26 15:14:25 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

void	*routine()
{
	int	i;

	i = 0;
	while (i < 10000)
	{
		mails++;
		// read mails
		// increment
		// write mails
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;

	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		perror("ERROR1\n");
	if (pthread_create(&t2, NULL, &routine, NULL) != 0)
		perror("ERROR2\n");
	if (pthread_join(t1, NULL) != 0)
		perror("ERROR3\n");
	if (pthread_join(t2, NULL) != 0)
		perror("ERROR4\n");
		printf("mails: %d\n", mails);
	return (0);
}
