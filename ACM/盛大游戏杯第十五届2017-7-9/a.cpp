#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int a[200],b;
		memset(a,0,sizeof(a));
		for(int i = 0; i < n;i++)
		{
			for(int j = 0;j < m;j++)
			{
				scanf("%d",&b);
				if(b)
				{
					a[j]++;
				}
			}
		}
		for(int j = 0; j < m-1;j++)
		{
			printf("%d ",a[j]);
		}
		printf("%d\n",a[m-1]);
		
	}	




 return 0;
}


