#include<stdio.h>
#include<math.h>
int main()
{
	double a[3];
	scanf("%lf%lf%lf",&a[0],&a[1],&a[2]);
	int F = 0;
	int FF = 0;
	double sum = 0;
	for(int i = 0;i < 3;i++)
	{
		if(a[i] == a[(i+1)%3])
		{
			FF++;
		}
		if(a[i]+a[(i+1)%3]<=a[(i+2)%3])
		{
			F = 1;
		}
		if(fabs(a[i]-a[(i+1)%3])>=a[(i+2)%3])
		{
			F = 1;
		}
		sum += a[i];
	}
	if(F)
	{
		printf("不是三角形\n");
		return 0;
	}
	if(FF == 0)
	{
		printf("周长为 %.2f 的一般三角形\n",sum);
	}
	else if(FF == 1)
	{
		printf("周长为 %.2f 的等腰三角形\n",sum);
	}
	else
	{
		printf("周长为 %.2f 的等边三角形\n",sum);
	 } 


 return 0;
}


