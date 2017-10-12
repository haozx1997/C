#include<bits/stdc++.h>

using namespace std;
int a[100100];

struct node
{
	int aa;
	int step;
	
 }; 

int dfs()
{
	
}

int main()
{

	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		
		int F = 0;
		if(n%2)
		{
			F = 1;
		}
		for(int i =2;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if(i == (n)&&a[i] == 2)
			{
				F = 1;
			}
		}
		F = dfs(n);
		if(F)
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

