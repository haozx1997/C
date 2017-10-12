#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,m;
	int a[10100];
	int b[10100];
	
	while(~scanf("%d%d",&n,&m))
	{
		for(int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		while(m--)
		{
			int l,r,x;
			scanf("%d%d%d",&l,&r,&x);
			if(x<l||x>r)
			{
				printf("No\n");
				continue;
			}
			int ll = 0;
			for(int i = l;i <= r;i++)
			{
				if(a[i]<a[x])
				{
					ll++;
				}
			}
	//		printf("%d %d\n",ll,x-l);
			if(ll != (x-l))
			{
				printf("No\n");
			}
			else
			{
				printf("Yes\n");
			}
		}
	}




 return 0;
}


