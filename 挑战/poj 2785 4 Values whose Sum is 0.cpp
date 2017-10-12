#include<stdio.h>
#include<algorithm>

#define ll long long
using namespace std;

ll a[5000];
ll b[5000];
ll c[5000];
ll d[5000];
ll ab[17000000];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i = 0; i < n;i++)
		{
			scanf("%lld%lld%lld%lld",&a[i],&b[i],&c[i],&d[i]);
			
		}
		
		long long ans = 0ll;
		for(int i = 0; i < n;i++)
		{
			for(int j = 0; j < n;j++)
			{
				ab[i*n+j] = a[i]+b[j]; 
			}
		
		}
		sort(ab,ab+n*n);
		for(int i = 0; i < n;i++)
		{
			for(int j = 0; j < n;j++)
			{
				int cd = -c[i]-d[j];
				ans +=(ll)(upper_bound(ab,ab+n*n,cd)-lower_bound(ab,ab+n*n,cd));
			}
		
		}
		printf("%lld\n",ans);
		
		
	}




 return 0;
}


