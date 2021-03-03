#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd, nbytes;
	char ch[16384];
    int characters, words, lines;
	fd=open("example.txt",O_RDONLY);

	if(fd<0)
	{
		perror("open");
		exit(1);
	}

   
    words = 0,lines = 0;
    while(nbytes = read(fd,ch,sizeof(ch)))
    {
        for(int i=0;i<nbytes;i++)
        {
            //Check new line
            if (ch[i] == '\n')
               lines++;

            //Check words */
            if (ch[i] == ' ' || ch[i] == '\t' || ch[i] == '\n')
               words++;
        }
        characters = nbytes;
    }

    printf("Total characters : %d\n", characters);
    printf("Total words      : %d\n", words);
    printf("Total lines      : %d\n", lines);


    //Close files to release resources
    close(fd);

    return 0;
}