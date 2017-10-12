#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
using namespace std;


int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		long long ans = 1;
		for(int i = n;i > 1;i--)
		{
			ans = (ans+1)*2;
		}
		printf("%lld\n",ans);
	}
}
