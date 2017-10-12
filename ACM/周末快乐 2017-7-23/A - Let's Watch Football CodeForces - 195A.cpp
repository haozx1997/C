#include<bits/stdc++.h>

using namespace std;

int main()
{

	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c))
	{
		int ans = ((a-b)*c+b-1)/b;
		
		printf("%d\n",ans);
	}


 return 0;
}
/*
4 1 1
10 3 2
13 12 1

*/ 

