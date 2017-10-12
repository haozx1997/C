#include<stdio.h>
//		 3B + A
// x = ---------
// 		4(A + B)

long long gcd(long long a,long long b)
{
	return !b ? a : gcd( b , a%b ) ;
}
int main()
{
	long long T;
	long long a,b;
	scanf("%I64d",&T);
	while(T--)
	{
		scanf("%I64d%I64d",&a,&b);
		long long fz = 3*b + a;
		long long fm = 4*(a+b);
		long long g = gcd(fz,fm);
		printf("%I64d/%I64d\n",fz/g,fm/g);
	}
}
