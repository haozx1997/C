#include<bits/stdc++.h>

using namespace std;
long long M = 1e9+7;
long long pow(long long x,long long n)
{
	long long ans = 1;
	for(int i = 0;i < n;i++)
	{
		ans *= x;
		ans %= M;
	}
	return ans;
}

int main()
{
	long long T;
	scanf("%I64d",&T);
	while(T--)
	{
		long long k,n;
		scanf("%I64d%I64d",&n,&k);
		long long sum = (long long)0;
		for(long long i = 1; i <= n;i++ )
		{
		
			sum += pow(i,k);
			
			sum %= M;
		}
		printf("%I64d\n",sum);
		
		
	}




 return 0;
}


