#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int a[200];
	while(~scanf("%d",&n))
	{
		for(int i = 0;i < n;i++ )
		{
			scanf("%d",a+i);
		}
		for(int i = 0 ;i < n-1;i++)
		{
			for(int j = 0;j < n-i-1;j++)
			{
				if(a[j]>a[j+1])
				{
					int t = a[j+1];
					a[j+1] = a[j];
					a[j] = t;
					printf("%d %d\n",j+1,j+1+1);
				}
			}
		}
//		for(int i = 0;i < n;i++ )
//		{
//			printf("%d%c",a[i],i != n-1 ? ' ':'\n');
//		}
	}




 return 0;
}


