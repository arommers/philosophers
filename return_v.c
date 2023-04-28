/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   return_v.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: arommers <arommers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/28 15:41:16 by arommers      #+#    #+#                 */
/*   Updated: 2023/04/28 16:06:29 by arommers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void	*roll_dice()
{
	int	value;
	int	*result;

	value = (rand() % 6) + 1;
	result = malloc(sizeof(int));
	*result = value;
	// printf("roll: %d\n", value);
	printf("Thread result: %p\n", result);
	return ((void *)result);
}

int	main(int argc, char **argv)
{
	int			*result;
	pthread_t	thread;

	srand(time(NULL));
	if (pthread_create(&thread, NULL, &roll_dice, NULL) != 0)
		return (1);
	if (pthread_join(thread, (void **) &result) != 0)
		return (2);
	printf("Main result: %p\n", result);
	printf("result: %d\n", *result);
	free(result);
	return (0);
}
