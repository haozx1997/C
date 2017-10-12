#include<stdio.h>
#include<algorithm>
#include<string.h>


using namespace std;

int r,c,ec,exc;
int vis[600][600];
int count1[600][600];

int wall[1010][1010];
int dir[4][2]={0,-1,1,0,0,1,-1,0};

int check(int sx,int sy,int i)
{	

	int ex = sx+dir[i][0];
	int ey = sy+dir[i][1];
	if(ex<0||ey<0||ex>=r||ey>=c)
	{
		return 0;
//		printf("!!1\n");
	}
	if(vis[ex][ey] == 1)
	{
		return 0;
//		printf("!!2\n");
	}
	switch(i)
	{
		case 0:
			if(wall[2*sx+1][sy-1] == 1)
			{
//				printf("%d %d %d %d %d",sx,sy,2*sx+1,sy-1,wall[2*sx+1][sy-1]);
//				printf("!!3\n");
				return 0;
			}
			break;
		case 1:
			if(wall[2*sx+2][sy] == 1)
			{
//				printf("!!4\n");
				return 0;
			}
			break;
		case 2:
			if(wall[2*sx+1][sy] == 1)
			{
//				printf("!!5\n");
				return 0;
			}
			break;
		case 3:
			if(wall[2*sx][sy] == 1)
			{
//				printf("!!6\n");
				return 0;
			}
			break;
			
	}
	return 1;
}
int FF = 0;
int dfs(int sx,int sy,int ex,int ey,int pre,int out)
{
	if(FF == 1)
	{
		return 0;
	}
	vis[sx][sy] = 1;
	count1[sx][sy] = 1;
	int nx = sx;
	int ny = sy;
//	printf(" %d %d\n",nx,ny);
	
	
		int four = 3;
		int i = pre;
		while(four--)
		{
			i %= 4;
			if(nx == ex&&ny == ey&&i == out)
			{
				FF = 1;
				return 0;
			}
			int nextx = sx+dir[i][0];
			int nexty = sy+dir[i][1];
			if(check(nx,ny,i))
			{
//				printf("%d %d %d\n",nextx,nexty,i);
				vis[nextx][nexty] = 1;
				count1[sx][sy] = 1;
				dfs(nextx,nexty,ex,ey,(i+3)%4,out);
			}
			i++;
		}
	return 0;
}



int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		memset(wall,0,sizeof(wall));
		memset(count1,0,sizeof(count1));
		
		scanf("%d%d%d%d",&r,&c,&ec,&exc);
		for(int i = 1;i < 2*r;i++)
		{
			if(!(i%2))//2 4
			{
				for(int j = 0;j < c;j++)
				{
					scanf("%d",&wall[i][j]);
				}
			}
			else//1 3
			{
				for(int jj = 0;jj < c-1;jj++)
				{
					scanf("%d",&wall[i][jj]);
				}
			}
		}
//		for(int i = 0;i < 2*r-1;i++)
//		{
//			if(i%2)//1 3
//			{
//				for(int j = 0;j < c;j++)
//				{
//					printf("%d ",wall[i][j]);
//				}
//			}
//			else//0 2
//			{
//				for(int jj = 0;jj < c-1;jj++)
//				{
//					printf("%d ",wall[i][jj]);
//				}
//			}
//			printf("\n"); 
//		}
//		
//		for(int i = 0;i < 7;i++)
//		{
//			for(int j = 0;j<4;j++)
//			{
//				printf("%d ",wall[i][j]);
//			}
//			printf("\n");
//		}
		FF = 0;
		dfs(0,ec,r-1,exc,0,1);
		
		int sum = 0;
		
		
		memset(vis,0,sizeof(vis));
		FF = 0;
		dfs(r-1,exc,0,ec,2,3);
		
		for(int i = 0;i < r;i++)
		{
			for(int j = 0;j<c;j++)
			{
				sum+=count1[i][j];
			}
		}
//		printf("%d\n",sum);
		if(sum == r*c)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	
}

