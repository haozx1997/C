/*
�ж�˭���ܹ�ʤ�����Ƿ��������������ˣ�
���������������ȡ��ʤ��������Ƿ���
���������ȡ�ߵ�ʤ�����ж��ǲ���������
���ĵ�������Ƶ�ʱ�򣬱���������a,b�����
�����Ƚ�����a<b,Ȼ���i=b-a,����������
�ƣ������m=floor(i*(1+sqrt(5.0))/2),����
b=m+i,����Ȳ���������ƣ�
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
���ϵ�ǰ�߰� 
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
int check(long long a,long long b)//��������Ʒ���1 
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
