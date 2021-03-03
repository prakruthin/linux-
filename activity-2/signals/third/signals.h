#ifndef __SIGNALS_H
#define __SIGNALS_H

#include <signal.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
void childpro();
void sighup(); 
void sigint(); 
void sigquit(); 

#endif