#include<bits/stdc++.h>

using namespace std;

struct node
{
	int next[600];
	int nn;
	int c;
}p[600];

int main()
{
	int v,k,e;
	while(~scanf("%d%d%d",&v,&e,&k))
	{
		
		memset(p,0,sizeof(p));
		
		for(int i = 0;i < e;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			p[a].next[p[a].nn++] = b;
			p[b].next[p[b].nn++] = a;
			
		}
		int sn;
		scanf("%d",&sn);
		while(sn--)
		{
			set<int>S;
			S.clear();
			
			for(int i = 1;i <= v;i++)
			{
				scanf("%d",&p[i].c);
				S.insert(p[i].c);
			}
			if(S.size()!=k)
			{
				printf("No\n");
				continue;
			}
			int f = 0;
			for(int i = 0;i < v;i++)
			{
				for(int j = 0;j < p[i].nn;j++)
				{
					if(p[i].c == p[p[i].next[j]].c)
					{
						f = 1;
						break;
					}
				}
				if(f == 1)
				{
					break;
				}
			}
			if(f == 1)
			{
				printf("No\n");
			}
			else
			{
				printf("Yes\n");
			}
			
			
		}
		
		
		
	}




 return 0;
}


