#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<map>
#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n,m;
		long long a[100100];
		scanf("%I64d%I64d",&n,&m);
		for(long long i = 0;i < n-1 ;i++)
		{
			scanf("%I64d",&a[i]);
			
		}
		long long sum = 0;
		sort(a,a+n-1);
		for(long long i = 0;i < (n-1-(m-1));i++)
		{
			sum += (a[i]+1);
		}
//		printf("%lld\n",sum);
		sum++;
		for(long long i = 0;i < (m-1);i++)
		{
			sum++;
		}
		printf("%I64d\n",sum);
	}
}
