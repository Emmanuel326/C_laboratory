#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdint.h>
#include <time.h>

#define ITERATIONS 100000000

 typedef struct shared_data
{
	long x;
	long y; //thread 2 touches this

};

 static struct share_data data;

void* thread1(void*arg)
{
	for(long i=0; i<ITERATIONS; i++)
	{
		data.x++;
	}
	return NULL;
}

void* thread2(void* arg)
{
	for(long i=0; i<ITERATIONS; i++)
	{
		data.y++;
	}
	return NULL;
}
double now()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return ts.tv_sec + ts.tv_nsec *1e-9;
}

int main()
{
	pthread_t t1, t2;

	double start=now();

	pthread_create(&t1, NULL, thread1, NULL);
	pthread_create(&t2, NULL, thread2, NULL);

	pthread_join(t1 , NULL);
	pthread_join(t2, NULL);


	double end = now();

	printf("Result: x=%ld, y=%ld\n", data.x, data.y);
	printf("Time: %.6f seconds\n", end - start);

	return 0;
}

