#include<stdio.h>
#include<string.h>

int f(int n)
{
	if(n == 1 || n==0 ) return 1;
	int ans=1;
	for(int j = n-1;j>0;j--)
	{
		
		ans += f(j);
	}
	return ans;
	
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int i;
		scanf("%d",&i);
		printf("%d\n",f(i));
	}
}
