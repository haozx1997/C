#include<stdio.h>
#include<algorithm>
#include<string.h>


using namespace std;

int r,c,ec,exc;
int vis1[600][600];
int vis2[600][600];

int wall[1010][1010];
int dir[4][2]={0,-1,1,0,0,1,-1,0};

int check1(int sx,int sy,int i)
{	

	int ex = sx+dir[i][0];
	int ey = sy+dir[i][1];
	if(ex<0||ey<0||ex>=r||ey>=c)
	{
		return 0;
//		printf("!!1\n");
	}
	if(vis1[ex][ey] == 1)
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

int check2(int sx,int sy,int i)
{	

	int ex = sx+dir[i][0];
	int ey = sy+dir[i][1];
	if(ex<0||ey<0||ex>=r||ey>=c)
	{
		return 0;
//		printf("!!1\n");
	}
	if(vis2[ex][ey] == 1)
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

int FF1 = 0;
int FF2 = 0;

int dfs1(int sx,int sy,int ex,int ey)
{
	if(FF1 == 1)
	{
		return 0;
	}
	vis1[sx][sy] = 1;
	int nx = sx;
	int ny = sy;
	printf("%d %d\n",nx,ny);
	
		if(nx == ex&&ny == ey)
		{
			FF1 = 1;
			return 0;
		}
		for(int i = 0;i < 4;i++)
		{
			int nextx = sx+dir[i][0];
			int nexty = sy+dir[i][1];
			if(check1(nx,ny,i))
			{
//				printf("%d %d %d\n",nextx,nexty,i);
				vis1[nextx][nexty] = 1;
				dfs1(nextx,nexty,ex,ey);
			}
		}
	return 0;
}


int dfs2(int sx,int sy,int ex,int ey)
{
	if(FF2 == 1)
	{
		return 0;
	}
	vis2[sx][sy] = 1;
	int nx = sx;
	int ny = sy;
	printf("%d %d\n",nx,ny);
	
		if(nx == ex&&ny == ey)
		{
			FF2 = 1;
			return 0;
		}
		for(int i = 0;i < 4;i++)
		{
			int nextx = sx+dir[i][0];
			int nexty = sy+dir[i][1];
			if(check2(nx,ny,i))
			{
//				printf("%d %d %d\n",nextx,nexty,i);
				vis2[nextx][nexty] = 1;
				dfs2(nextx,nexty,ex,ey);
			}
		}
	return 0;
}



int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(vis1,0,sizeof(vis1));
		memset(vis2,0,sizeof(vis2));
		memset(wall,0,sizeof(wall));
		FF1 = 0;
		FF2 = 0;
		
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
		
		dfs1(0,ec,r-1,exc);
		
		dfs2(r-1,exc,0,ec);
		int sum = 0;
		for(int i = 0;i < r;i++)
		{
			for(int j = 0;j<c;j++)
			{
				sum+=vis1[i][j];
			}
		}
		for(int i = 0;i < r;i++)
		{
			for(int j = 0;j<c;j++)
			{
				sum+=vis2[i][j];
			}
		}
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

