#include<stdio.h>

int main()
{
	int n[5] = {1,2,3,4,5};
	int* p = n;
	for(int i = 0;i < 5;i++)
	{
		printf("%d �ĵ�ַ %lld \n",n[i],n+i);//��int ��4���ֽ�
		
	}
	for(int i = 0;i < 5;i++)
	{
		printf("%lld �����ַ�ı�����ֵ%d \n",p+i,*(p+i));
		
	}
	for(int i = 0;i < 5;i++)
	{
		printf("%d\n",p[i]);
		
	}	
	
	
}
