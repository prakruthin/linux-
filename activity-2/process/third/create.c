#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>

int main()
{
	int ret,i,ret1,ret2,status;
	printf("welcome..pid=%d\n",getpid());
	ret=fork();
    
	if(ret<0)
	{
		perror("fork");
		exit(1);
	}
	if(ret==0)
	{
        int k;
    
        k=execl("/usr/bin/g++","g++","Kill.c","-c",NULL);

		if(k<0)
		{
			perror("execl");
			exit(1);
		
        }
	}
        ret1=fork();
		if(ret1<0)
		{
			perror("fork");
			exit(1);
		}
		if(ret1==0)
		{
			int k1;
			k1=execl("/usr/bin/g++","g++","Kill.c","-c",NULL);
			if(k1<0)
			{
				perror("execl");
				exit(1);
			
			}
		}
            ret2=fork();
			if(ret2<0)
			{
				perror("fork");
				exit(1);
			}
			if(ret2==0)
			{
				int k2;
				k2=execl("/usr/bin/g++","g++","kill","-o","Build_Multiple_File",NULL);
				if(k2<0)
				{
					perror("execl");
					exit(1);
				
				}
				exit(15);
			}
			//exit(5);
		    //exit(15);
    
    
	else	
	{
		waitpid(-1,&status,0); 
        int k3;
        k3=execlp("./Build_Multiple_File",NULL);
		if(k3<0)
		{
			perror("execlp");
			exit(1);
        }
		printf("parent--child exit status=%d\n",WEXITSTATUS(status));
	}
	return 0;
  
}