#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;
int f[1010][1010];
int max(int x,int y)
{
	return x>y? x:y;
}

set <int> out;
set <int> :: iterator it;

int main()
{
	int T,TT = 1;
	scanf("%d",&T);
	while(T--)
	{
		out.clear();
		int n,v;
		scanf("%d%d",&v,&n);
		int vv[1010],w[1010];
		for(int i = 1;i<=n;i++)
		{
			scanf("%d%d",&vv[i],&w[i]);
		}
		printf("	%d %d\n",n,v);
		for(int i =1 ; i <= n;i++)
		{
			printf("	%d %d\n",vv[i],w[i]);
		}
		memset(f,0,sizeof(f));
		for(int i = 1;i<=n;i++)
		{
			for(int j = v;j>=vv[i];j--)
			{
				if(f[i-1][j]<f[i-1][j-w[i]]+vv[i])
				 {
				 	f[i][j] = f[i-1][j-w[i]]+vv[i];
				 	out.insert(i);
				 }
				 else
				  {
				  	  f[i][j] = f[i-1][j];
				  
					}  
				     printf("!!%d %d %d\n",i,j,f[i][j]);   
			}
			
		}
		printf("%d %d\n",f[n][v],f[n][v]);
		printf("Case #%d:\n",TT++);
		int ccc = 0,sss = 0;
		for(it = out.begin();it!=out.end();it++)
		{
			ccc += vv[*it];
			sss += w[*it];
		}
		printf("%d %d\n",sss,ccc);
		if(f[n][v])
		{
			it = out.begin();
			printf("%d",*it);
			for(it++;it!=out.end();it++)
			{
				printf(" %d",*it);
			}
			puts("");
		}
	 } 
}
