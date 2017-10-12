#include<bits/stdc++.h>

using namespace std;

const long long M = 1000000007;
long long n,l;

long long pm(long long a, long long b,long long c)

{

	long long ans = 1;
	
	a = a % c;
	
	while(b>0)
	
	{
	
	if(b % 2 == 1)
	
	ans = (ans * a) % c;
	
	b = b/2;
	
	a = (a * a) % c;
	
	}
	
	return ans;

}

long long init(long long n)
{
	if(n <= (long long)0)
	{
		return 0;
	}
	if(n == (long long)1)
	{
		return (long long)1;
		
	}
	if(n == (long long)2)
	{
		return (long long)2;
		
	}
	return pm(2,n-1,M);
	
}

int main()
{
	
	while(~scanf("%lld%lld",&n,&l))
	{
		long long pres;long long a[100100];
		if(l>=n)
		{
			printf("%lld\n",init(n));
		}
		else
		{
			//long long pre = init(l-3);
			pres = 0;
			
			memset(a,0,sizeof(a));
			
			for(int i = 0;i <= l;i++)
			{
				a[l-i] = (init(l-i)%M);
				pres += (a[l-i]%M);
				pres %= M;
			}
			
			for(int i = l+1;i<=n;i++)
			{
				a[i] = pres;
				pres += (a[i]%M);
				pres %= M;
				 
				pres -= (a[i-l]%M);
				pres %= M;
				
				
				
			}
		}
		printf("%lld\n",a[n]);
		
		
	}
	
 return 0;
}


