#include<stdio.h>

long A(int n)
  {

	if(n==1||n==0)
	 n=1;
	else
	 n=n*A(n-1);
	return n;
	
  }
int main()
{  int a;
scanf("%d",&a); 
printf("%d!=%d",a,A(a));
}


