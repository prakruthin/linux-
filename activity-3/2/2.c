/*
program to Implement producer consumer problem using circular buffer operations using semaphores

*/
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
//max value and buffer size
#define MaxItems 3 
#define BufferSize 3 


sem_t start;
sem_t stop;
int in = 0;
int out = 0;
int buffer[BufferSize];

void *producer(void *prod_num)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand(); // Produce a random item
        sem_wait(&start);
        /* wait for space in buffer */
        while (((in + 1) % BufferSize) == out)
        {
        /* put value item into the buffer */
           buffer[in] = item;
           printf("Producer %d inserted Item %d at %d\n", *((int *)prod_num),buffer[in],in);
           in = (in + 1) % BufferSize;     
        }
        sem_post(&stop);
    }
}
void *consumer(void *cons_num)
{   
    int item=0;
    for(int i = 0; i < MaxItems; i++) {
        sem_wait(&stop);
        while (in == out) 
        {
           item = buffer[out];
           printf("Consumer %d removed Item %d from %d\n",*((int *)cons_num),item, out); 
           out = (out + 1) % BufferSize;     
        }
        sem_post(&start);
    }
}

int main()
{   

    pthread_t prod[5],cons[5];
    sem_init(&start,0,BufferSize);
    sem_init(&stop,0,0);

    int arr[3] = {1,2,3}; 

    for(int i = 0; i < 3; i++) {
        pthread_create(&prod[i], NULL, (void *)producer, (void *)&arr[i]);
    }
    for(int i = 0; i < 3; i++) {
        pthread_create(&cons[i], NULL, (void *)consumer, (void *)&arr[i]);
    }

    for(int i = 0; i < 3; i++) {
        pthread_join(prod[i], NULL);
    }
    for(int i = 0; i < 3; i++) {
        pthread_join(cons[i], NULL);
    }

    sem_destroy(&start);
    sem_destroy(&stop);

    return 0;
}