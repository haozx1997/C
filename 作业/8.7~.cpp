#include<stdio.h>
#include<string.h>
int main()
{
	int b[1024],B[1024];
	int a,i=0,j=0;
    scanf("%d",&a);
	for(;a>0;i++)
	   {
	   	b[i]=a%2;
	   	a=a/2;
	   	printf("%d",b[i]);
	   }
	   printf("\n");
	   for(;j<=i+1;j++,i--)
	    {
		B[j]=b[i-1];
        printf("%d",B[j]);
        }
        return B[0];


}
