#include<bits/stdc++.h>

using namespace std;

char s[200][200];

int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		int x1,x2,y1,y2,sum;
		x1 = y1 = 10000;
		sum = x2 = y2 = 0;
		for(int i = 0;i < n;i++)
		{
			scanf("%s",&s[i]);
		}
		for(int i = 0;i < n;i++)
		{
			for(int j = 0;j < m;j++)
			{
				if(s[i][j] == 'B')
				{
					x1 = min(x1,i);
					y1 = min(y1,j);
					x2 = max(x2,i);
					y2 = max(y2,j);
					sum ++;
				}
			}
		
		}
		if(sum == 0)
		{
			printf("1\n");
			continue;
		}
		int ans = max(x2-x1+1,y2-y1+1);
		if(ans>m||ans>n)
		{
			printf("-1\n");
			continue;
		}
	//	printf("%d %d\n",ans,sum);
		printf("%d\n",ans*ans-sum);
		
	}




 return 0;
}


