#include<stdio.h>
#include<iostream>

using namespace std;

int F = 0;
int dfs(unsigned long long k,int n,int l)
{
	if(F)
	{
		return 0;
	}
	if((k%n) == 0)
	{
		F = 1;
//		cout<<k<<endl;
		printf("%I64u\n",k);
		return 0;
	}
	if(l == 19)
	{
		return 0;
	}
	dfs(k*10,n,l+1);
	dfs(k*10+1,n,l+1);
	
}

int main()
{
	int n;
	
	while(scanf("%d",&n),n)
	{
		F = 0;
		dfs(1,n,0);
	
	}
	return 0;
}
