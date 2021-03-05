#include"message.h"
//#include <bufing.h>

int main()
{
	int ret,nbytes; 
	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=5;
	mqd_t mqid;
	mqid=mq_open("/mqueue",O_RDONLY|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf[8192];
	int maxlen=256,prio;
	nbytes=mq_receive(mqid,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	buf[nbytes]='\0';
	printf("message recived from sender:%s, nbytes=%d, prio=%d\n",buf,nbytes,prio);
	mqd_t mqid2;
	struct mq_attr attr2;
	attr2.mq_msgsize=256;
	attr2.mq_maxmsg=5;
	mqid2=mq_open("/mqueue2",O_WRONLY|O_CREAT,0666,&attr2);
	for(int counter=0;buf[counter]!=NULL;counter++)
    {
		//convert into lower case
        if(buf[counter]>='A' && buf[counter]<='Z')
            buf[counter]=buf[counter]+32;   
		//convert into upper case
        else if(buf[counter]>='a' && buf[counter]<='z')
            buf[counter]=buf[counter]-32;   
    }
	ret=mq_send(mqid2,buf,nbytes+1,2);
	if(ret<0)
	{
		perror("mq_send");
		exit(2);
	}
	//write(1,buf,nbytes);
	mq_close(mqid);
	mq_close(mqid2);
	
	return 0;
}

