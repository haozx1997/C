#include <iostream>
#include <set>
#include <stdio.h>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;
long long n,m,t;
int add(long long q)
{
	if(q<=n)
	{
	
		t++;
		add(q*2);
		add(q*2+1);
		
	}
	return 0;
}

int main()
{
	
	while(scanf("%I64d%I64d",&m,&n),n&&m)
	{
		t = 0;
		add(m);
		printf("%I64d\n",t);
	}
}
