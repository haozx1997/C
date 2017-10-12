#include<bits/stdc++.h>

using namespace std;

int n;

int dp(int a)
{
	//printf("dp %d\n",a);
	switch(a)
	{
		case 1 : return a;
		case 2 : return a;
		case 3 : return a;
		case 4 : return a;
		default :break;
	}
	return dp(a-1)+dp(a-3);
}

int main()
{
	
	while(scanf("%d",&n),n)
	{
		
		printf("%d\n",dp(n));
	}
}
