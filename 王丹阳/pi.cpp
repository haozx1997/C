#include<stdio.h>
#include<math.h>
int main()
{	
	float pi,sum = 0;
	int i,n;
	scanf("%d",&n);
	for(i = 1;i<=n;i++)
	{
		sum += (float)1/i/i;	//��1ǿ��ת��Ϊfloat���ܳ�����ΪС�� 
	}	
	pi = sqrt(6*sum);//sqrt�ǿ������� 
	printf("n=%d pi=%f\n",n,pi);
}
