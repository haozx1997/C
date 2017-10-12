#include<stdio.h>
#include<string.h>
#include<stack>
#include<stdlib.h>
using namespace std;
int x,y;
char s[110][110];
int m[110][110];
int dfsn;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int is(int xx,int yy,int n)
{
	if(xx<0||yy<0||xx>=x||yy>=y||
		m[xx][yy]==1||s[xx][yy]!=n)
	   return 0;
	return 1;	
}

int dfs(int i,int j)
{
	if(is(i,j,s[i][j]))
	{
		dfsn++;
		m[i][j] = 1;
		for(int d = 0;d < 4; d++)
		{
			if(is(i+dir[d][0],j+dir[d][1],s[i][j]))
			{
				dfs(i+dir[d][0],j+dir[d][1]);
			}
		}
	}
	return 0;
}




int main()
{
	

	memset(m,0,sizeof(m));
	scanf("%d%d",&x,&y);
	for(int i = 0;i < x;i++)
	{
		scanf("%s",s[i]);
	}
	int max = 1;
	for(int i = 0;i < x;i++)
	{
		for(int j = 0;j < y;j++)
		{
			dfsn = 0;
			dfs(i,j);
			if(dfsn>=max)
			 {
			 	max = dfsn;
			 }
		}
	}
	printf("%d\n",max);
	
}
