#include<stdio.h>
int Z(int n)
{//[设计型]输入一个整数k（2≤k≤10000），打印它的所有的质因子。例如：输入90，打印出2、3、3、5。
	int a,b,i=0;
	int z[10000];
	for(a=2;a<10000;a++)
	  {
		for(b=2;b<a;b++)
		  {
		  	if((a%b)==0) break;
		  };
		if(b==a)
		  {
		  	z[i]=a;
		  	i++;
		  } ;
	  } 
	return z[n];
}
int main()
{
	int a,i;
	while(~scanf("%d",&a))
	{
		for(i=0;a!=1;)
		{
			if(a%Z(i)) i++;
			else
			 {
			 	a=a/Z(i);
			 	printf("%d ",Z(i));
			 }
		}
		printf("\n");
	}
	return 0;
} 
