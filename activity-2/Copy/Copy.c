#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	int fd, fd1, nbytes;

    //Opening file1 to read the data from the file
	fd = open("file1.txt",O_RDONLY);

    //Opening file2 to write the data which is in file1 to file2
	fd1 = open("file2.txt",O_WRONLY|O_CREAT, 0666);

    //Checking the condition of the file
	if(fd<0 || fd1<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen = 128;
	char buf[maxlen];

    //Reading nbytes from the file1
	nbytes=read(fd,buf,maxlen);

    //Checking whether the data was added into file2 from file1 are not
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
    
    //Writing read into file2
	write(fd1,buf,nbytes);

    //Closing the files which are opened
	close(fd);
    close(fd1);
	return 0;
}