#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#define MaxInt 0x3f3f3f

using namespace std;

struct GG
{
	int arcs[110][110];
	int vexnum,arcnum;
};
int vis[10010];
int dis[10010];
int path[110];
int n,ln;


void Dij(GG G , int st)
{
	memset(vis,0,sizeof(vis));
	for(int i = 1;i <= G.vexnum;i++)
	{
		dis[i] = G.arcs[st][i];
		if(G.arcs[st][i] < MaxInt)
		{
			
			path[i] = st;
			
		}
		else
		{
			
			path[i] = -1;
		}
		
	}
	vis[st] = 1;
	dis[st] = 0;
	int vnext = st;
	
	for(int i = 2; i <=G.vexnum;i++ )
	{
		int min = MaxInt;
		for(int ii = 1;ii <= G.vexnum;ii++)
		{
			if(!vis[ii]&&dis[ii]<min)
			{
				vnext = ii;
				min = dis[ii];
			}
			
		}
		vis[vnext] = 1;
		for(int ii = 1 ;ii <= G.vexnum;ii++)
		{
			if(!vis[ii]&&(dis[vnext]+G.arcs[vnext][ii]<dis[ii]))
			{
				dis[ii] = dis[vnext]+G.arcs[vnext][ii];
				path[ii] = vnext;
			}
		}
	}
}

int main()

{
	
	
	while(scanf("%d%d",&n,&ln),n)
	{
		GG G;
		memset(G.arcs,-1,sizeof(G.arcs));
		
		memset(dis,0,sizeof(dis));
		
		
		G.vexnum = n;
		 
		G.arcnum = ln;
		 for(int i=1;i<=n;++i)  
        {  
            for(int j=1;j<=n;++j)  
            {  
                G.arcs[i][j]=MaxInt;  
            }  
        }
		
		for(int i = 0;i < ln;i++)
		{
			int ou_,in_,v_;
			scanf("%d%d%d",&ou_,&in_,&v_);
			if(v_<G.arcs[ou_][in_])
			{
				G.arcs[ou_][in_] = v_;
				G.arcs[in_][ou_] = v_;
			
			}
		}
		Dij(G,1);
		//printf(" !!%d\n",G.arcs[2][1]);
		printf("%d\n",dis[n]);
		
		
	}
}
