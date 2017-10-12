#include<stdio.h>
#include<stack>
#include<string.h>

const int maxn = 105;
char mm[maxn][maxn];
int m,n,dirx[maxn][maxn];
void dfs (int i,int j)

{
	 int t;

	int di,dj;
	if(i<0||i>=m||j<0||j>=n)return;
	if(dirx[i][j]>0||mm[i][j]!='W')return;
	dirx[i][j]=1;
	mm[i][j]='.';
	for(di=-1;di<=1;di++)
	 for(dj=-1;dj<=1;dj++)
	  if(di!=0||dj!=0)dfs(i+di,j+dj);
	
	
}

int main()
{
	int i,j;
	while(scanf("%d%d",&m,&n)==2&&m&&n);
	{
		for(i=0;i<m;i++) scanf("%s",mm[i]);
		memset(dirx,0,sizeof(dirx));
		
		int cnt=0;
		
		for(i=0;i<m;i++)
		 for(j=0;j<n;j++)
		  if(dirx[i][j]==0&&mm[i][j]=='W') cnt++,dfs(i,j);
		 printf("%d\n",cnt);
	}
}


