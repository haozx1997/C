#include<stdio.h> 
int main() 
{  
	int a,b[100],i=0,j;
  	printf("Input data:\n");
    scanf("%d",&a);         //������Ҫת��������
	while(a)  
	{   
	 	b[i]=a%3;     //��������������������b��;
		a/=3;      //�������������3����ֵ������a;
		i++;   
	}
   for(j=i-1;j>=0;j--)     //�����������b�е�����Ϊ���������ֵ���������  
	{   
		printf("%d",b[j]);
	}  
		printf("\n"); 
}
