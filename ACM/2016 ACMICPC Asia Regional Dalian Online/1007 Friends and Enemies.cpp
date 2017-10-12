#include<stdio.h>


int main()
{
	long long n,m,n_r;
	while(~scanf("%I64d%I64d",&n,&m))
	{
		n_r = (1+n)*n/2;
		if(n_r <= m)
		 printf("T\n");
		else
		  printf("F\n");
	}
}
