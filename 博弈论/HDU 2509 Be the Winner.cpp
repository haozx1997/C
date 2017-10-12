#include<stdio.h>
int main()
{
	int n;
	
	while(~scanf("%d",&n))
	{
		int f = 0;
		int ans = 0;
		int a;
			 
		for(int i = 0;i < n ;i++)
		{
			scanf("%d",&a);
			if(a!=1)f = 1;
			ans ^= a;
		}
		char aa[2][10]={{"Yes"},{"No"}};
		
		
		if(f)
		printf("%s\n",aa[ans==0]);
		else
		printf("%s\n",aa[n%2]);
	}
}
