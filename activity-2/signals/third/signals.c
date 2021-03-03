#include "signals.h"

void childpro()
{ 
    int pid; 
  
    /* get child process */
    if ((pid = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) { /* child */
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        /* forever loop */
        for (;;) 
            ; 
    } 
  
    else /* parent */
    { /* pid hold id of child */
        printf("\nPARENT: sending SIGHUP\n\n"); 
        kill(pid, SIGHUP); 
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGINT\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3); /* pause for 3 secs */
        printf("\nPARENT: sending SIGQUIT\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 

void sighup()   
{ 
    signal(SIGHUP, sighup); /* reset signal */
    printf("sig up--> child process\n"); 
} 

void sigint() 
  
{ 
    signal(SIGINT, sigint); /* reset signal */
    printf("sig init--> child process\n"); 
} 
  
void sigquit() 
{ 
    printf("sig quit--> end of process\n"); 
    exit(0); 
} 
