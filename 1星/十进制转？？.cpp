#include<stdio.h>
#include<string.h>


int main()
{ 
	int a,aa;
	int b[1024],B[1024];
	
	scanf("%d",&aa);
	
	
	int I = 2; //2~10 进制 
	{
		int i = 0,j; 
		a = aa;
		memset(b,0,sizeof(b));
		while(a)  
		{   
		 	b[i]=a%I;     //输入的数字求余存入数组b中;
			a/=I;      //输入的数字整除3并赋值给变量a;
			i++;   
		}
		printf("%d ",I);
	   for(j=i-1;j>=0;j--)     //反向输出数组b中的数即为所输入数字的三进制数  
		{   
			printf("%d",b[j]);
		}  
			printf("\n"); 
		
		
		
		
	}

}

