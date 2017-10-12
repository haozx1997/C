#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
#include <windows.h>
#define random(x) (rand()%x)

   

int main()
{
	int N;
	

	while(1)
	{
		SYSTEMTIME sys;
	    GetLocalTime(&sys);
		srand((sys.wMilliseconds)*100);
		N=random(1000000);
		printf("%d ",N);
		if(N==0||N==1)
		 {
		 	printf("No\n");
		 	continue;
		 }
		char a[10];
		memset(a,0,sizeof(a));
		sprintf(a,"%d",N);
		int i,f=1,l=strlen(a);
		for(i=0;i<l/2;i++)
		{
			if(a[i]!=a[l-i-1]) 
			{
				f=0;
				break;
			}
		}
		int F=1,j;
		for(j=2;j*j<N;j++)
		  {
				if(!(N%j))
					{
						F=0;
						break;	
					 }	  	
		  	
		  }
		  if((j*j)==N) F=0;
		if(f&&F)
		printf("Yes\n");
		else printf("No\n");
	
		
	}
}
