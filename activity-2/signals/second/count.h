#ifndef __COUNTFILE_H
#define __COUNTFILE_H

#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void checkFile();
int getLines();
int getChars();
int getWords();

#endif