#include<bits/stdc++.h>

using namespace std;

int main()
{

	int a,b,c;
	while(~scanf("%d%d",&a,&b))
	{
		int mm = b - a*2;
		int d = min(a,mm);
		
		printf("%d\n",a - d);
	}


 return 0;
}
/*
4 1 1
10 3 2
13 12 1

*/ 

