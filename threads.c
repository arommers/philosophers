#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *routine()
{
	printf("test\n");
	sleep (3);
	printf("ending thread\n");
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;
	if (pthread_create(&t1, NULL, &routine, NULL) != 0)
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL) !=0)
		return (2);
	if (pthread_join(t1, NULL)!= 0)
		return (3);
	return (0);
}