#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int sum[300000];
int vis[300000];


int main()
{
	int n,a;
	while(~scanf("%d",&n))
	{
		int maxn = 0;
		memset(sum,0,sizeof(sum));
		memset(vis,0,sizeof(vis));
		
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a);
			maxn = max(a,maxn);
			vis[a]= 1;
			sum[a]++; 
		}
		for(int i = 1;i <= maxn;i++)
		{
			
			sum[i] += sum[i-1];
			
		}
//		for(int i = 0;i < maxn;i++)
//		{
//			
//			printf("	%d %d\n",i,sum[i]);
//			
//		}
		
		long long ans = 0ll;
		for(int i = 1;i <= maxn;i++)
		{
			if(vis[i] == 0)
			{
				continue;
			}
			long long s = 0ll;
			for(int j = i;j <= maxn;j+=i)
			{
				int r = min(maxn,i+j-1);
	//			printf("%d %d %I64d\n",j,r,(long long)sum[r] - sum[j-1]);
				s += ((long long)sum[r] - sum[j-1])*j;
				
			}
	//		printf("i %d s	%I64d\n",i,s);
			ans = max(ans,s);
		}
		
		
		printf("%I64d\n",ans);
		
		
		
		
		
	 } 


/*

4
3 2 15 9
4
8 2 2 7

*/

 return 0;
}


