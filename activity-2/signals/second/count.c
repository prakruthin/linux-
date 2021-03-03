#include "count.h"

int lines, chars, words;
void checkFile()
{
	int fd,nbytes;
	char ch[16384];
  fd=open("text.txt",O_RDONLY);
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
  words = 0,lines = 0;
    while(nbytes=read(fd,ch,sizeof(ch)))
    {
        for(int i=0;i<nbytes;i++)
        {
            /* Check new line */
            if (ch[i] == '\n')
               lines++;
            /* Check words */
            if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
               words++;
        }
        chars=nbytes;
    }
    /* Close files to release resources */
    close(fd);
}

int getLines()
{
  return lines;
}
int getChars()
{
  return chars;
}
int getWords()
{
  return words;
}
