#include"message.h"
int main()
{
	int temp;
	mqd_t mqid;

	struct mq_attr attr;
	attr.mq_msgsize=256;
	attr.mq_maxmsg=5;
	mqid=mq_open("/mqueue",O_WRONLY|O_CREAT,0666,&attr);
	if(mqid<0)
	{
		perror("mq_open");
		exit(1);
	}
	char str[]="Hi LTTS";
	int len=strlen(str);
	temp=mq_send(mqid,str,len+1,3);
	if(temp<0)
	{
		perror("mq_send");
		exit(2);
	}
	struct mq_attr attr2;
	attr2.mq_msgsize=256;
	attr2.mq_maxmsg=5;
	mqd_t mqid2;
	mqid2=mq_open("/mqueue2",O_RDONLY|O_CREAT,0666,&attr2);
	if(mqid2<0)
	{
		perror("mq_open");
		exit(1);
	}
	char buf[8192];
	int maxlen=256,prio;
	int nbytes=mq_receive(mqid2,buf,maxlen,&prio);
	if(nbytes<0)
	{
		perror("mq_recv");
		exit(2);
	}
	
	buf[nbytes]='\0';
	printf("message recived from receiver :%s, nbytes=%d, prio=%d\n",buf,nbytes,prio);
	mq_close(mqid);
	mq_close(mqid2);
	return 0;
}

