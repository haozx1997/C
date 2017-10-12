#include<stdio.h>
#include<string.h>
#include <iostream>
#include <set>

using namespace std;
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
		int n,v,d;
		scanf("%d%d%d",&n,&v,&d);
		int vv[1010],w[1010];
		for(int i = 1;i<=n;i++)
		{
			scanf("%d",&vv[i]);
		}
		for(int i = 1;i<=n;i++)
		{
			scanf("%d",&w[i]);
		}
		set<int> S; 
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
		    	S.insert(f[i][j]);
				   
			}
			
		}
		int ans[1010] ,ii = 0;
		set<int>::iterator it; 
        for(it=S.begin();it!=S.end();it++) 
        {
        	ans[ii] = *it;
        	printf("%d ",ans[ii])
        	ii++;
		}
		printf("%d\n",ans[ii-d]);
		
	 } 
}
