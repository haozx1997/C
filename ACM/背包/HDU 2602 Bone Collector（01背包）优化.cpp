#include<stdio.h>
#include<string.h>
int f[1010][1010];
int max(int x,int y)
{
	return x>y? x:y;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,v;
		scanf("%d%d",&n,&v);
		int vv[1010],w[1010];
		for(int i = 1;i<=n;i++)
		{
			scanf("%d",&vv[i]);
		}
		for(int i = 1;i<=n;i++)
		{
			scanf("%d",&w[i]);
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
				 }
				 else
				    f[i][j] = f[i-1][j];
				   //  printf("!!%d %d %d\n",i,j,f[i][j]);   
			}
			
		}

		printf("%d",f[n][v]);
		
	 } 
}
