#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		long long a[100100];
		long long ans = 0;
		for(int i = 0; i < n;i++ )
		{
			scanf("%lld",&a[i]);
			ans += (long long)(a[i]*(i+1));
		}
		//printf("123\n");
		long long minn = 1111111111111111111;
		long long now;
		long long now_ = 0;
		now = (long long)a[k]*k;
		for(int j = 0;j<k;j++)
		{
			now_ += a[j];
		}
		minn = min(minn,now-now_);
		for(int i = k+1; i < n;i++ )
		{
			now = (long long)a[i]*k;
			now_ -= a[i-k-1];
			now_ += a[i-1];
		//	printf("now  %d %lld\n",i,now);
			minn = min(minn,now-now_);
		}
		printf("%lld\n",ans-minn);
		
	}





 return 0;
}


