#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxx = 1010;
const ll mod = (ll)1e9+7;

int n,m,k;
int p[1000];
int d;

int main()
{
	
	while(~scanf("%d%d",&n,&m))
	{
		for(int i = 0; i <n;i++ )
		{
			scanf("%d",&p[i]);
		}
		scanf("%d",&k);
		for(int i = 0; i <k;i++ )
		{
			scanf("%d",&d);
			p[d] = -1;
		}
		int mmm = m;
		for(int i = n-1;i>=0;i--)
		{
			if(p[i] != -1)
			{
				mmm--;
			}
			
			if(!mmm)
			{
				mmm = i;
				break;
			}
		}
		int ans = INT_MAX;
		int a,b;
		for(int i = 0; i <= mmm;i++)
		{
			if(p[i] == -1)
			{
				continue;
			}
			int mm = m;
			for(int jj = 1;jj<mm;jj++)
			{
				int j = i+jj;
				if(p[j] == -1)
				{
					mm++;
					continue;
					
				}
				if(j>=n)
				{
					break;
				}
				int now = p[i]+p[j];
				
				if(now<ans)
				{
					ans = now;
					a = i;
					b = j;
				}
			}
		}
		printf("%d %d\n",a,b);
	 } 





 return 0;
}


