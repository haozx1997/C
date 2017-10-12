#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		int a[100];
		int sum = 0;
		scanf("%d",&n);
		for(int i = 0;i < n;i++)
		{
			int an,ai;
			int mm = 10000;
			scanf("%d",&an);
			for(int j = 0; j < an;j++)
			{
				scanf("%d",&ai);
				mm = min(mm,ai);
			}
			sum += (20-mm-(an-1));
			
		}
	//	printf("%d\n",sum);
		if(sum%2)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}




 return 0;
}


