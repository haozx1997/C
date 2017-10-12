#include<stdio.h>
#include<string.h>

int u,v,w;
int n,m,s,d;
int matr[600][600];
int path[600];
int dist[600];
int pv[600];
int vis[600];
int help[600];

void DijkstraPath(int s)
{
	int i,j,k;
	int vis[600];
	for(i = 0;i<n;i++)
	{
		if(matr[s][i]>0&&i!=s)
		{
			dist[i] = matr[s][i];
			path[i] = s;
			pv[i] = help[s]+help[i];
		}
		else
		{
			dist[i] = 600;
			path[i] = -1;
		}
		vis[i] = 0;
		path[s] = s;
		dist[s] = 0;		
		
	}	
	vis[s] = 1;
	for(i = 1;i<n;i++)
	{
		int min = 600;
		int uu;
		for(j = 0;j<n;j++)
		{
			if(vis[j]==0&&dist[j]<min)
			{
				min = dist[j];
				uu = j;
			}
		}
		vis[uu] = 1;
		for(k = 0;k < n; k++)
		{
			if(vis[k] == 0&&matr[uu][k]>0&&min+matr[uu][k]<dist[k])
			{
				dist[k] = min + matr[uu][k];
				path[k] = uu;
			}
			else if(vis[k] == 0&&matr[uu][k]>0
				&&min+matr[uu][k]==dist[k]&&pv[j]<pv[uu]+help[j])
				{
					pv[j]=pv[uu]+help[j];
					path[k] = uu;
				}
		}
	}
}


int main()
{

	scanf("%d%d%d%d",&n,&m,&s,&d);
	
	memset(matr,0,sizeof(matr));
	for(int i = 0; i < n;i++)
	{
		scanf("%d",&help[i]);
	}
	for(int i = 0; i < m;i++)
	{
		scanf("%d",&u);
		scanf("%d",&v);
		scanf("%d",&w);
		matr[u][v] = w;
	}
	DijkstraPath(s);
	int way[600];
	int l=0;
	int allhelp = 0;	
	while(1)
	{
		
		way[l++] = d;
		allhelp +=help[d];
		d = path[d];
		
		if(d == s )
		{
			way[l++] = d;
			allhelp +=help[d];
			d = path[d];
			break;
		}
	}
	printf("%d %d\n",--l,allhelp);
	for(int i = l;i>=0;i--)
	{
		
		printf("%d",way[i]);
		if(i)
		printf(" ");
	}
	
	
 } 
