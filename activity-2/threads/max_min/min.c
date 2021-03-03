#include "MaxMin.h"

int MinArray[1000] = {0}, minarr[10] = {0};

void *task_body_min(void *pv)
{
  int i, thread_num = (__intptr_t)pv, tempmin = 0;  
  for(i=0; i<100; ++i)
  {
    /* Searching minimum in 100 array values*/
    if(MinArray[thread_num * 100 + i] < tempmin)
    {
      tempmin = MinArray[i];
    }
  }
  minarr[thread_num] = tempmin;
}

int findMin()
{
  int n=10, i, tempmin = 0;
  pthread_t ptrarr[n];

  srand(time(0));

  for(i=0; i<1000; i++)
  {
    /* Assigning random value to Array */
    MinArray[i] = random()%100;
  }
  for(i=0; i<n ; ++i)
  {
    /* Create a thread to search 100 array values */
    pthread_create(&ptrarr[i], NULL, task_body_min, (void*)(__intptr_t) i);
  }
  for(i=0; i<n ; ++i)
  {
    pthread_join(ptrarr[i], NULL);
  }
  for(i=0; i < n; ++i)
  {
    /* Find Maximum from thread results*/
    if(minarr[i] < tempmin)
    {
      tempmin = minarr[i];
    }
  }
  return tempmin;
}