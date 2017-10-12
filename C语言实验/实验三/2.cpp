#include<stdio.h>
#include<math.h>
int main()
{//求出数列2/1，3/2，5/4，8/8，…的前10项之和
	double a=0,b=1,c=1,d=1,i=1;
	for(;i<12;i++)
	  {
	  b=c-b;
	  c=b+c;
	  if(pow(2,i-2)<1)continue ;
	  a=a+(c)/pow(2,i-2) ;
	  printf("%f/%f_\n",c,pow(2,i-2));
	  }
	  printf("=%f",a);
	  return 0;
}
	
	
