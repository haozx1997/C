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
		printf("����������\n");
		return 0;
	}
	if(FF == 0)
	{
		printf("�ܳ�Ϊ %.2f ��һ��������\n",sum);
	}
	else if(FF == 1)
	{
		printf("�ܳ�Ϊ %.2f �ĵ���������\n",sum);
	}
	else
	{
		printf("�ܳ�Ϊ %.2f �ĵȱ�������\n",sum);
	 } 


 return 0;
}


