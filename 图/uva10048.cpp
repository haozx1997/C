#include <cstdio>  
#include <cstring>  
#include <algorithm>  
#include <vector>  
#include <queue>  
#include <iostream>
using namespace std;  
  
const int INF = 100010;  
const int maxn =  500 + 5;  

int d[111][111];
void floyd(int n,int an)
{
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
		{
			d[i][j] = INF;
		}
	for(int i = 0;i < n;i++)
	{
		d[i][i] = 0;
	}
	int x,y,v;
	for(int i = 0;i < an;i++)
	{
		scanf("%d%d%d",&x,&y,&v);
		x--;y--;
		d[x][y] = v;
		d[y][x] = v;
		
	}
	for(int i = 0; i < n;i++)
	{
		for(int ii = 0; ii < n;ii++)
		{
			for(int iii = 0; iii < n;iii++)
			{
				d[ii][iii] = min(d[ii][iii],
					min(d[ii][i],d[i][iii]));
			}	
		}
	}
}

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	int n,an,q;
	while(scanf("%d%d%d",&n,&an,&q),n)
	{
		floyd(n,an);
		while(q--)
		{
			int s,e;
			scanf("%d%d",&s,&e);
			s--;e--;
			printf("%d\n",d[s][e]);
		}
	}
	
 } 




 
