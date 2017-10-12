#include<bits/stdc++.h>

using namespace std;

int s[111][111][30];
int h[111][111];



int main()
{
	int n,q,c;
	while(~scanf("%d%d%d",&n,&q,&c))
	{
		memset(s,0,sizeof(s));
		for(int i = 0;i < n;i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			s[x][y][z]++;
			
		}
		for(int i = 1;i <= 100;i++)
		{
			for(int j = 1;j <= 100;j++)
			{
				for(int k = 0;k <= 10;k++)
				{
					s[i][j][k] += s[i][j-1][k]+s[i-1][j][k]-s[i-1][j-1][k];
				}
			}
		}
		
		
		for(int i = 0;i < q;i++)
		{
			int t,x1,x2,y1,y2;
			int ans = 0;
			scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
			for(int i = 0;i <= 10;i++)
			{
				ans += ((s[x2][y2][i]-s[x1-1][y2][i]-s[x2][y1-1][i]+s[x1-1][y1-1][i])*((t+i)%(c+1)));
			}
			printf("%d\n",ans);
		}
	}





 return 0;
}


