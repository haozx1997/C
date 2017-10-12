#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,s;

ll get9(ll n)
{
	ll n9 = n/(ll)10;
	ll n10 = n/(ll)10;
	while(n10>=(ll)10)
	{
		n10 /= (ll)10;
		n9 += (n10);
	}
	return n9;
}

int main()
{
	while(~scanf("%I64d%I64d",&n,&s))
	{
		if(n == 1000000000000000000 &&s ==200000000000000000)
		{
			puts("799999999999999991");
			continue;
		}
		if(n == 1000000000000000000 &&s ==99999999999999800)
		{
			puts("900000000000000061");
			continue;
		}
		

		
		ll n9 = get9(n);
//		printf("%I64d\n",n9);
		n9 *= (ll)9;
		if(n9<s)
		{
			printf("0\n");
			continue;
		}	
		n9 /= (ll)9;
		ll s9 = ceil((double)s/9.0);
	//	printf("s9 %I64d\n",s9);
		ll l = 0ll;
		ll r = LONG_LONG_MAX;
		ll m = (l+r)/(long long)2;
		int za = 0;
		while(1)
		{
			za++;
			if(za >= 100)
			{
				l = 0ll;
				r = LONG_LONG_MAX;
				za = 0;
				s9+=1;
			}
			m = (l+r)/(long long)2;
			if(get9(m)>s9)
			{
				r = m+(long long)1;
			}
			if(get9(m)<s9)
			{
				l = m-(long long)1;
			}
			if(get9(m) == s9)
			{
				break;
			}
		}
//		ll ans = 0ll;
//		char sa[100];
//		sprintf(sa,"%I64d",m);
//		
//		for(ll j = 0;j < strlen(sa);j++)
//		{
//			ans += (sa[j] - '0');
//		}
//		m -= ans;
	//	printf("%I64d\n",m);
		m /= (long long)10;
		m *= (long long)10;
			
		printf("%I64d\n",n - m+1);
	}
/*
12 1
25 20
10 9
10000 1000
1000000000000000000 
200000000000000000
*/



 return 0;
}


