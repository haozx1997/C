#include<bits/stdc++.h>
#define ll long long
using namespace std;
	ll a[100100];
		ll b[100100];
		ll c[100100];
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		ll sum1 = 0;
		ll sum2 = 0;
	
		
		for(int i = 0;i < n;i++)
		{
			scanf("%I64d",&a[i]);
			sum1 += a[i];
			c[i] = i;
		}
		for(int i = 0;i < n;i++)
		{
			scanf("%I64d",&b[i]);
			sum2 += b[i];
		}
		int p = n/2 + 1;
		printf("%d\n",p);
		while(1)
		{
			ll sum1c = 0;
			ll sum2c = 0;
			random_shuffle(c,c+n);
			for(int i = 0;i<p;i++)
			{
				sum1c += a[c[i]];
				sum2c += b[c[i]];
				
			}
		//	printf("%I64d %I64d\n",sum1c,sum2c);
			if(sum1<sum1c*2&&sum2<sum2c*2)
			{
				break;
			}
		}
		for(int i = 0;i<p;i++)
		{
			printf("%d ",c[i]+1);
		}
		puts("");
		
		
		
		
		
		
	}




 return 0;
}


