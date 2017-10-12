#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int main()
{
	long long x;
	while(~scanf("%lld",&x))
	{

		if(x<0)
		{
			x = -x;
		}
		long long n = 0;
		long long nn = 0;
		
		while(n<x||((n-x)%2))
		{
			n += (++nn);
		}
	
			printf("%lld\n",nn);
	
		
	}
}






