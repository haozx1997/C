#include<bits/stdc++.h>

using namespace std;

struct node
{
	int x,y;
	int step;
};

int n,m,k;
char mi[400][400];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int vis[200][200];
int aim[10][10];
int find;
int fx,fy;
int ans;


int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(mi,0,sizeof(mi))
		memset(vis,0,sizeof(vis))
		memset(aim,0,sizeof(aim))
		
		for(int i = 0;i <= n+1;i++)
		{
			for(int j = 0;j<=m+1;j++)
			{
				&mi[i][j] = '.';
			}
		}
		
		
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				scanf("%c",&mi[i][j]);
			}
		}
		
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j<=m;j++)
			{
				if(mi[i][j] == '.'&&mi[i-1][j] == '.'&&mi[i][j-1] == '.')
				{
					
				}
				if(mi[i][j] == '.'&&mi[i+1][j] == '.'&&mi[i][j-1] == '.')
				{
					
				}
				if(mi[i][j] == '.'&&mi[i+1][j] == '.'&&mi[i][j+1] == '.')
				{
					
				}
				
			}
		}
		
		
	}






 return 0;
}


