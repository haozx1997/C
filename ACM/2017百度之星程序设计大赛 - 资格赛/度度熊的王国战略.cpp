#include<bits/stdc++.h>
#define ll long long
using namespace std;

int c[4000];


int main()
{
	int n,m,u,v,w;
	while(~scanf("%d%d",&n,&m))
	{
		memset(c,0,sizeof(c));
		for(int i = 0 ; i < m;i++)
		{
			
			scanf("%d%d%d",&u,&v,&w);
			if(u == v)
			continue;
			c[u] += w;
			c[v] += w;
			
		}
		int ans = INT_MAX;
		for(int i = 1; i <= n;i++)
		{
			ans = min(ans,c[i]);
		}
		printf("%d\n",ans);
	}




 return 0;
}


