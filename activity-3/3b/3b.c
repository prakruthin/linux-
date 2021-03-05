/*
program to Implement producer consumer problem using circular buffer operations using mutex

*/
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
//max value and buffer size
#define MaxItems 3 
#define BufferSize 3 
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void *prod_num)
{   
    int item;
    for(int i = 0; i < MaxItems; i++) {
        item = rand(); // Produce a random item
        pthread_mutex_lock(&mutex);
        /* wait for space in buffer */
        while (((in + 1) % BufferSize) == out)
        {
        /* put value item into the buffer */
           buffer[in] = item;
           printf("Producer %d inserted Item %d at %d\n", *((int *)prod_num),buffer[in],in);
           in = (in + 1) % BufferSize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}
void *consumer(void *cons_num)
{   
    int item=0;
    for(int i = 0; i < MaxItems; i++) {
        pthread_mutex_lock(&mutex);
        while (in == out) 
        {
           item = buffer[out];
           printf("Consumer %d removed Item %d from %d\n",*((int *)cons_num),item, out); 
           out = (out + 1) % BufferSize;     
        }
        pthread_mutex_unlock(&mutex);
    }
}

int main()
{   

    pthread_t prod[5],cons[5];
 

    int arr[3] = {1,2,3,4,5,6,7,8,9,3}; 

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

    pthread_mutex_destroy(&mutex);


    return 0;
}