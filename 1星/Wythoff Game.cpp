/*
判断谁个能够胜利看是否是奇异矩阵就行了，
如果是奇异矩阵，则后取者胜利，如果是非奇
异矩阵，则先取者得胜！在判断是不是咸佐夫
博弈的奇异局势的时候，比如两个数a,b，则可
以首先交换是a<b,然后记i=b-a,如果是奇异局
势，则必有m=floor(i*(1+sqrt(5.0))/2),并且
b=m+i,否则比不是奇异局势！
(0,0)
(1,2)
(3,5)
(4,7)
(6,10)
(8,13)
(9,15)
(11,18)
(12,20)
(14,23)
(16,26)
符合的前者败 
*/
#include<stdio.h>
#include<string.h>
#include<math.h>
int a[100100],b[100100];
void Wythoff()
{
	for(int i = 0;i < 100001;i++)
	{
		a[i] = floor(i*(1.0+sqrt(5.0))/2);
		b[i] = a[i] + i;
	}
}
int check(long long a,long long b)//是奇异局势返回1 
{
	if(a > b)
	{
		long long t = a;
		a = b;
		b = t;
	}
	long long i = b - a;
	long long m = floor(i*(1+sqrt(5.0))/2);
//	printf("%lld %lld\n",m,a);
	return (m == a);
 } 
int main()
{
	int n;
	Wythoff();
	
	while(~scanf("%d",&n))
	{
		for(long i = 0;i <= n;i++)
		{
			printf("(%d,%d)\n",a[i],b[i]);
		}
		printf("\n");		
	}
	
}
