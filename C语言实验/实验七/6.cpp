#include<stdio.h>
int main()
{ //编写函数把一个十进制正整数转换为二进制数 
	int a,b,c;
	int two(int);
	scanf("%d",&a);
	two(a);

}
int *two(int a)
{
	int b[1024],B[1024];
    int i=0,j=0;
    for(;a>0;i++)
	   {
	   	b[i]=a%2;
	   	a=a/2;
	   }
	for(;j<=i+1;j++,i--)
	    {
		B[j]=b[i-1];
        printf("%d",B[j]);
        }
         printf("\n");
       

}
