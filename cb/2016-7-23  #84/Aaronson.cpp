#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

long long er[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,
524288,1048576,2097152,4194304,8388608,16777216,33554432,
67108864,134217728,268435456,536870912,1073741824};


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n,m;
		long long ans = 0;
		scanf("%I64d%I64d",&n,&m);
		long long nn = n;
		if(m>30)
		 m = 30;
		long long I = m;
		while(nn!=1&&nn!=0)
		{
			for(long long  i = I;i>=0;i--)
			{	

				if(er[i]<=nn)
				{
					I = i;
					break;
				}
				
			}
			
			nn -= er[I];
			ans++;
		}
		if(nn==1)
		 ans++;
		printf("%I64d\n",ans);
		
	}
}
