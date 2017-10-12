#include<bits/stdc++.h>

using namespace std;

int main()
{

	int n ;
	int a[2000];
	while(~scanf("%d",&n))
	{
		int pre ,now;
		scanf("%d",&pre);
		int fff =0;
		int h0 = 0;
		for(int i = 0;i < n-1;i++)
		{
			scanf("%d",&now);
		//	printf("%d %d\n",pre,now);
			if(pre>now)
			{
				a[i] = -1;
				fff = 1;
			}
			if(pre==now)
			{
				a[i] = 0;
				h0 = 1;
			}
			if(pre<now)
			{
				a[i] = 1;
				fff = 1;
			}
			pre = now;
		}
		if(fff == 0||n == 1)
		{
			printf("YES\n");
			continue;
		}
		int e = a[0];
		int FFF = 0;
		for(int i = 0;i < n-1;i++)
		{
		//	printf("%d %d\n",e,a[i]);
			if(i == 0&&a[i]!=e)
			{
				FFF = 1;
				
				break;
			}
			if(e>=a[i])
			{
				e = a[i];
			}
			else if(e<a[i])
			{
				FFF = 1;
				break;
			}
		}
		if(FFF)
		printf("NO\n");
		else
		printf("YES\n");
				
		
	}




 return 0;
}

/*

6
1 5 5 5 4 2
5
10 20 30 20 10
4
1 2 1 2
7
3 3 3 3 3 3 3


*/

