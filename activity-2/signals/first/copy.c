#include "copy.h"
bool copyFileCont()
{
	int ptr,ptr1,nbytes, flag;
	ptr=open("text1.txt",O_RDONLY);
	ptr1=open("text2.txt",O_WRONLY|O_CREAT, 0666);
	if(ptr<0 || ptr1<0)
	{
		perror("open");
		exit(1);
	}
	int maxlen=128;
	char buf[maxlen];
	nbytes=read(ptr,buf,maxlen);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	flag = write(ptr1,buf,nbytes);
	close(ptr);
	close(ptr1);
	if(flag)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
		





