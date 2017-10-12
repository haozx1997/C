#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
	return b == 0? a:gcd(b,a%b);
}

int main()
{

	int x,k;
	while(~scanf("%d%d",&x,&k))
	{
		for(int kk = 2;kk<=k;kk++)
		{
			printf("%d\n",kk/gcd(kk,x));
		}
		
	}



 return 0;
}


