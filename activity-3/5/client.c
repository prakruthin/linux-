#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mqueue.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>


int main()
{
	int ret,n_bytes;
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=5;
	mqd_t mq_id;
	mq_id=mq_open("/mque1",O_RDONLY|O_CREAT,0666,&attr);
	
	if(mq_id<0)
	{
		perror("mq_open");
		exit(1);
	}
	
	char buffer[8192];
	int Max_len=256,prio;
	n_bytes=mq_receive(mq_id,buffer,Max_len,&prio);
	if(n_bytes<0)
	{
		perror("mq_reciver");
		exit(2);
	}
	
	buffer[n_bytes]='\0';
	int temp;
    printf("%s",buffer);
	
	temp=execlp("/bin/gcc","gcc",buffer,0);
    if(temp<0)
		{
			perror("execlp");
			exit(1);
		}
		exit(5);
		
	printf("message recived is:%s,nbytes=%d,prio=%d\n",buffer,n_bytes,prio);
	mq_close(mq_id);
	return 0;
}

