#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[100100];
const int mod = 1e9+7;



long long quick_mul(ll a,ll b)
{
	ll yaoyuan = 0;
	while(b)
	{
		if(b&1)
		{
			yaoyuan = (yaoyuan+a)%mod;
		}
		a = (a+a)%mod;
		b>>=1; 
	}
	return yaoyuan;
}

long long quick_pow(ll a,ll b)
{
	ll yaoyuan = 1;
	while(b)
	{
		if(b&1)
		{
			yaoyuan = quick_mul(yaoyuan,a)%mod;
		}
		a = quick_mul(a,a)%mod;
		b>>=1; 
	}
	return yaoyuan;
}


int main()
{
	int n;
	
	while(~scanf("%d",&n))
	{
		memset(a,0,sizeof(a));
		int sum = 0;
		ll ans = 0ll;
		int ai;
		for(int i = 0; i < n;i++)
		{
			scanf("%d",&ai);
			a[ai]++;
		}
		int F = 0;
		if(n%2)
		{
			if(a[0] == 1)
			{
				for(int i = 2;i < n;i+=2)
				{
					if(a[i]!=2)
					{
			//			printf("%d %d",i,a[i]);
						F = 1;
						break;
					}
				}
				
				
			}
			else
			{
				F = 1;
			}
		}
		else
		{
			for(int i = 1;i < n;i+=2)
			{
				if(a[i]!=2)
				{
					F = 1;
					break;
				}
			}
				
			
		}
		
		if(F)
		{
			printf("0\n");
		}
		else
		{
			
			printf("%I64d\n",quick_pow(2,n/2));
		}
		
		
		
		
	}

/*
5
2 4 4 0 2
 
7
6 4 0 2 4 0 2
 
8
7 5 1 1 7 3 5 3

*/


 return 0;
}


