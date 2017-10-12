#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	long long a[40010];
	while(~scanf("%d",&n))
	{
		n *= 2;
		for(int i = 0;i < n;i++)
		{
			scanf("%lld",&a[i]);
		}
		sort(a,a+n);
		long long ans = 0;
		for(int i = 0;i < n/2;i++)
		{
			ans += (long long)(a[i*2+1]-a[i*2]);
		}
		printf("%lld\n",ans);
	}




 return 0;
}


