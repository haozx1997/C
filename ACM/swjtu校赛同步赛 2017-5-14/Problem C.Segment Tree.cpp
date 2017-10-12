#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,q,k;
		int a[200];
		memset(a,0,sizeof(a));
		scanf("%d%d%d",&n,&k,&q);
		int maxx = 0;
		for(int i = 0;i < n;i++)
		{
			int kk;
			scanf("%d",&kk);
			if(kk>maxx) maxx = kk;
			a[kk]++;
		}
		int ans = 0;
		for(int i = 1;i<=maxx;i++)
		{
			int sum = 0;
			for(int j = i;j < i+k;j++)
			{
				sum += a[j];
			}
			
			if(sum >= q)
			{//printf("sum %d\n",sum);
				ans++;
			}
		}
		printf("%d\n",ans);
	}




 return 0;
}


