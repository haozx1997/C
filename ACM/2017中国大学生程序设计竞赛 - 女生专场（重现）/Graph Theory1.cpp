#include<bits/stdc++.h>

using namespace std;
int a;


int main()
{

	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		int que = -1;
		int F = 0;
		
		for(int i =2;i<=n;i++)
		{
			scanf("%d",&a);
			if(a == 1)
			{
				que++;
			}
			else
			{
				que--;
			}
			if(que>0)
			{
				que = 0;
			}
		}
		if(n%2)
		{
			printf("No\n");
			continue;
		}
		if(que>=0)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}


 return 0;
}

