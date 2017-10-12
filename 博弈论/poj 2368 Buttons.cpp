#include<stdio.h>
int main()
{
	int k;
	while(~scanf("%d",&k))
	{
		if(k==1||k==2||k==0) 
		{
			printf("0\n");
			continue;
		}
		if(k==4) 
		{
			printf("3\n");
			continue;
		}
		
		int f = 0;
		for(int i = 3;i*i <= k;i++ )
		{
			if((k%i)==0)
			 {
			 	f = i;
			 	break;
			  } 
		}
		if(!f&&!(k%2))
		{
			f = k/2;
		}
		
		if(f) 
		 {
		 	printf("%d\n",f-1);
		 }
		 else
		 {
		 	printf("%d\n",k-1);	
		 }
	}
	return 0;
}

