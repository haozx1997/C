#include<bits/stdc++.h>
#define ll long long
using namespace std;

int h[200][10];

int main()
{
	int n;
	while(~scanf("%d",&n)) 
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i = 0; i < n;i++)
		{
			scanf("%d%d",&h[i][0],&h[i][1]);
			h[i][2] = h[i][0]*h[i][1];
		}
		int ans = 0;
		for(int i = 0; i < n-1;i++)
		{
			for(int j = i+1;j < n;j++)
			{
				if(h[i][0]<=a&&h[i][1]<=b)
				{
					if(h[j][0]<=(a)&&h[j][1]<=(b-h[i][1]))
					{
						ans = max(ans,h[i][2]+h[j][2]);
						continue;
					}
					if(h[j][1]<=(a)&&h[j][0]<=(b-h[i][1]))
					{
						ans = max(ans,h[i][2]+h[j][2]);
						continue;
					}
					if(h[j][0]<=(a-h[i][0])&&h[j][1]<=(b))
					{
						ans = max(ans,h[i][2]+h[j][2]);
						continue;
					}
					if(h[j][1]<=(a-h[i][0])&&h[j][0]<=(b))
					{
						ans = max(ans,h[i][2]+h[j][2]);
						continue;
					}
					
				}
				if(h[i][0]<=b&&h[i][1]<=a)
				{
					if(h[j][0]<=(b)&&h[j][1]<=(a-h[i][1]))
					{
						ans = max(ans,h[i][2]+h[j][2]);
						continue;
					}
					if(h[j][1]<=(b)&&h[j][0]<=(a-h[i][1]))
					{
						ans = max(ans,h[i][2]+h[j][2]);
						continue;
					}
					if(h[j][0]<=(b-h[i][0])&&h[j][1]<=(a))
					{
						ans = max(ans,h[i][2]+h[j][2]);
						continue;
					}
					if(h[j][1]<=(b-h[i][0])&&h[j][0]<=(a))
					{
						ans = max(ans,h[i][2]+h[j][2]);
						continue;
					}
					
				}
			}
		}
		
		
		printf("%d\n",ans);
	}

/*

input
2 2 2
1 2
2 1

4 10 9
2 3
1 1
5 10
9 11

3 10 10
6 6
7 7
20 5


*/

 return 0;
}


