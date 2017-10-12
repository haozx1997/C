#include<stdio.h> 
int main() 
{  
	int a,b[100],i=0,j;
  	printf("Input data:\n");
    scanf("%d",&a);         //输入需要转换的数字
	while(a)  
	{   
	 	b[i]=a%3;     //输入的数字求余存入数组b中;
		a/=3;      //输入的数字整除3并赋值给变量a;
		i++;   
	}
   for(j=i-1;j>=0;j--)     //反向输出数组b中的数即为所输入数字的三进制数  
	{   
		printf("%d",b[j]);
	}  
		printf("\n"); 
}
