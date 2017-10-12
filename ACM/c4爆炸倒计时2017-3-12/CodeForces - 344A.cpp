#include<stdio.h>
#include<string.h>


int main()
{
	
	int n;
	while(~scanf("%d",&n))
	{
	
		int ans = 1;
		int nump = 0;
		int num = 0;
		
		scanf("%d",&nump);
		nump %= 10;
		for(int i = 1;i<n;i++)
		{
			scanf("%d",&num);
			num %= 10;
			if(num!=nump)
			{
				ans++;
			 } 
			
			nump = num;
		}
		printf("%d\n",ans);
		
	}
}
