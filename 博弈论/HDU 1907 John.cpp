#include<stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		int f = 0;
		int ans = 0;
		int a;
		scanf("%d",&n);	 
		for(int i = 0;i < n ;i++)
		{
			scanf("%d",&a);
			if(a!=1)f = 1;
			ans ^= a;
		}
		char aa[2][10]={{"John"},{"Brother"}};
		
		
		if(f)
		printf("%s\n",aa[ans==0]);
		else
		printf("%s\n",aa[n%2]);
	}
}
