#include<stdio.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;


int main()
{
	double n;
	while(~scanf("%lf",&n))
	{
		n = (double)n/2;
		double ans = (double)3.1415926/3*n*n*n*4;
		printf("%.2f\n",ans);
		
	}
}
