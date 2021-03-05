/*program to mplement producer consumer problem using Stack operations using semaphores*/

#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>
#include<stdio.h>

#define Max_items 3 // Maximum items a producer can produce or a consumer can consumer
#define Buffer_size 3 // Size of the buffer

int in = 0;
int out = 0;
int item=0;
int buffer[Buffer_size];
pthread_mutex_t mutex;


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
        pthread_mutex_lock(&mutex);
        item = buffer[out];
        printf("Consumer %d: Remove Item %d from %d\n",*((int *)con_num),item, out); 
        out = (out + 1) % Buffer_size;     
        pthread_mutex_unlock(&mutex);
     }
    }
}

void *producer(void *prod_num)
{   
    if(in==Buffer_size-1)
    {
        printf("stack is stop- Producer can produce \n");
    }
    else
    {
     for(int i = 0; i < Max_items; i++) {
        item = rand(); // Produce a random item
        pthread_mutex_lock(&mutex);
        /* put value item into the buffer */
        buffer[in] = item;
        printf("Producer %d: Insert Item %d at %d\n", *((int *)prod_num),buffer[in],in);
        in = (in + 1) % Buffer_size;     
        pthread_mutex_unlock(&mutex);
     }
    }
}

int main()
{   

    pthread_t prod[3],cons[3];
    pthread_mutex_init(&mutex, NULL);

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