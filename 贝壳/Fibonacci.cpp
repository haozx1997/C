#include<stdio.h>
#include<math.h>
//int main()
//{
//	long long a,b,c;
//	a = 0;b = 1;
//	printf("0 0\n1 1\n");
//	for(int i = 2;i < 100;i++)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		printf("%d %lld\n",i,c);
//		
//	}
// } 
// 

long long xy(long long x,long long y)
{
	long long xx = x;
	for(long long i = 0;i < y-1;i++)
	{
		x *= xx;
	}
	return x;
}

int main()
{
	printf("%d\n",xy(2,10));
	long double a;
	for(int i = 0;i < 100;i++)
	{
		a = (double)(  (xy(((1+sqrt(5)/(double)2)),i)) - (xy(((1-sqrt(5)/(double)2)),i))  )/(sqrt(5));
		printf("%d %Lf\n",i,a);
	}
}
