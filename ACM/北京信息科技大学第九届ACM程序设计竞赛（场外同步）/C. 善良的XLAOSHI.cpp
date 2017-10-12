#include<bits/stdc++.h>

using namespace std;

int main()
{	
	int T;
	scanf("%d",&T);
	int n,m,l[30100],k[30100];
	while(T--)
	{
		scanf("%d%d",&n,&m);
		memset(k,0,sizeof(k));
		memset(l,0,sizeof(l));
		
		
		for(int i = 0;i < n;i++ )
		{
			scanf("%d",&k[i]);
		}
		for(int i = 0;i < m;i++ )
		{
			scanf("%d",&l[i]);
		}
		if(n>m)
		{
			printf("Time up!\n");
			continue;
		}
		sort(k,k+n);
		sort(l,l+m);
		int j = m-1;
		int F = 0;
		for(int i = n-1;i>=0;i--,j--)
		{
		//	printf("%d %d\n",k[i],l[j]);
			if(k[i]>l[j])
			{
				F = 1;
				break;
			}
		}
		if(F)
		{
			printf("Time up!\n");
		}
		else
		{
			printf("You are pretty lucky!\n");
		}
	}





 return 0;
}


