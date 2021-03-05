#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int ret;
	mqd_t mq_id;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=5;
	mq_id=mq_open("/mque1",O_WRONLY|O_CREAT,0666,&attr);
	if(mq_id<0)
	{
		perror("mq_open");
		exit(1);
	}
	char str1[]="temp.c";
	int len=strlen(str1);
	ret=mq_send(mq_id,str1,len+1,5);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	mq_close(mq_id);
	return 0;
}

