#include<stdio.h>
#include<string.h>


int main()
{ 
	int a,aa;
	int b[1024],B[1024];
	
	scanf("%d",&aa);
	
	
	int I = 2; //2~10 ���� 
	{
		int i = 0,j; 
		a = aa;
		memset(b,0,sizeof(b));
		while(a)  
		{   
		 	b[i]=a%I;     //��������������������b��;
			a/=I;      //�������������3����ֵ������a;
			i++;   
		}
		printf("%d ",I);
	   for(j=i-1;j>=0;j--)     //�����������b�е�����Ϊ���������ֵ���������  
		{   
			printf("%d",b[j]);
		}  
			printf("\n"); 
		
		
		
		
	}

}

