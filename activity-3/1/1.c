/*program to mplement producer consumer problem using Stack operations using semaphores*/

#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>

#define Max_items 3 // Maximum items a producer can produce or a consumer can consumer
#define Buffer_size 3 // Size of the buffer

sem_t start;
sem_t stop;
int in = 0;
int out = 0;
int item=0;
int buffer[Buffer_size];


void *consumer(void *con_num)
{   
    if(out==Buffer_size-1)
    {
        printf("stack is empty- consumer can't consume\n");
    }
    else
    {
     int item=0;
     for(int i = 0; i < Max_items; i++) {
        sem_wait(&stop);
        item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)con_num),item, out); 
        out = (out + 1) % Buffer_size;     
        sem_post(&start);
     }
    }
}

void *producer(void *prod_num)
{   
    if(in==Buffer_size-1)
    {
        printf("stack is full- Producer can produce \n");
    }
    else
    {
     for(int i = 0; i < Max_items; i++) {
        item = rand(); // Produce a random item
        sem_wait(&start);
        /* put value item into the buffer */
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)prod_num),buffer[in],in);
        in = (in + 1) % Buffer_size;     
        sem_post(&stop);
     }
    }
}

int main()
{   

    pthread_t prod[3],cons[3];
    sem_init(&start,0,Buffer_size);
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