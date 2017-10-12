#include<bits/stdc++.h>

using namespace std;
struct node
{
	int op,k,v,I;
}opr[3000];

int cmp(node a,node b)
{
	return a.I<b.I;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,q;
		scanf("%d%d",&n,&q);
		int m[600][600];
		
		int op,k,vi;
		memset(m,0,sizeof(m));
		memset(opr,0,sizeof(opr));
		
		for(int i = 1;i <= q;i++)
		{
			scanf("%d%d%d",&op,&k,&vi);
			k--;
			op--;
			opr[op*n+k].v = vi;
			opr[op*n+k].I = i;
			opr[op*n+k].op = op;
			opr[op*n+k].k = k;
			
		}
		sort(opr,opr+2*n+10,cmp);
		for(int i = 0;i<2*n+10;i++)
		{
			//printf("%d %d %d\n",(*it)%10,(*it)/1000,vv[(*it)%10][(*it)/1000]);
		//	printf("opr %d\n",opr[i].I);
			if(opr[i].I == 0)
			{
			continue;
			}
			int op = opr[i].op,k = opr[i].k,vi = opr[i].v;
			if(op == 0)
			{
				for(int i = 0;i < n;i++)
				{
					m[k][i] = vi;
				}
			}
			else
			{
				for(int i = 0;i < n;i++)
				{
					m[i][k] = vi;
				}
			}
		}
		
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < n-1;j++)
			{
				printf("%d ",m[i][j]);
			}
			printf("%d\n",m[i][n-1]);
		}
		
	}




 return 0;
}


