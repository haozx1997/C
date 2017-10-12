#include<stdlib.h>

#include<stdio.h>
#include<string.h>


   

int main()
{
	int N;
	

		while(scanf("%d",&N)!=EOF)

	{
			

		if(N==0||N==1)
		 {
		 	printf("No\n");
		 	continue;
		 }
		char a[10000];
		memset(a,0,sizeof(a));
		sprintf(a,"%d",N);
		
		int i,f=1,l=strlen(a);
		if(l>5)
		{
		 	printf("No\n");
		 	continue;
		 }
		for(i=0;i<l/2;i++)
		{
			if(a[i]!=a[l-i-1]) 
			{
				f=0;
				break;
			}
		}
		if(!f) 
		{
			printf("No\n");continue;
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
