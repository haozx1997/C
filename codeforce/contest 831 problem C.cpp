#include<bits/stdc++.h>

using namespace std;

int k,n,a[3000],b[3000];

int main()
{
	int an = 0;
	while(~scanf("%d%d",&k,&n))
	{
		for(int i = 0;i < k;i++)
		{
			int aa;
			scanf("%d",&aa);
			if(aa)
			{
				a[an++] = aa;
			}
		}
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&b[i]);
		}
		
	}
	



 return 0;
}


