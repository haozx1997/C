/*
�ж�˭���ܹ�ʤ�����Ƿ��������������ˣ�
���������������ȡ��ʤ��������Ƿ���
���������ȡ�ߵ�ʤ�����ж��ǲ���������
���ĵ�������Ƶ�ʱ�򣬱���������a,b�����
�����Ƚ�����a<b,Ȼ���i=b-a,����������
�ƣ������m=floor(i*(1+sqrt(5.0))/2),����
b=m+i,����Ȳ���������ƣ�
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
