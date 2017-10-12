#include<stdio.h>
#include<string.h>


int main()
{
	
	int n;
	while(~scanf("%d",&n))
	{
		int c = 0;
		scanf("%d",&c);
		int ans = 1;
		int nump = 0;
		int num[100100];
		
		for(int i = 0;i<n;i++)
		{
			scanf("%d",&num[i]);
			
		}
		 for (int i = 1 ; i < n ; i++)  
	    {  
	        if (num[i] - num[i-1] <= c) 
	            ans++;  
	        else  
	            ans = 1;  
	    }  
		printf("%d\n",ans);
		
	}
}
