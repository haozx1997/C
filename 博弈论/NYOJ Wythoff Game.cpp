/*
判断谁个能够胜利看是否是奇异矩阵就行了，
如果是奇异矩阵，则后取者胜利，如果是非奇
异矩阵，则先取者得胜！在判断是不是咸佐夫
博弈的奇异局势的时候，比如两个数a,b，则可
以首先交换是a<b,然后记i=b-a,如果是奇异局
势，则必有m=floor(i*(1+sqrt(5.0))/2),并且
b=m+i,否则比不是奇异局势！
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
int main()
{
	int n;
	Wythoff();
	
	while(~scanf("%d",&n))
	{
		for(long i = 0;i <= n;i++)
		{
			printf("(%d,%d)",a[i],b[i]);
		}
		printf("\n");		
	}
	
}
