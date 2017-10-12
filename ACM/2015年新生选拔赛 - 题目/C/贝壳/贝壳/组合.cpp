#include<stdio.h>

long A(int n)
  {

	if(n==1||n==0)
	 n=1;
	else
	 n=n*A(n-1);
	return n;
	
  }
  long  C(int m,int n)
  { 
    long  a,b,c;
    a=A(n); printf("nn %d nn ",a);
    b=A(m); printf("mm %d mm",b);
    c=A(n-m); printf("n-m %d n-m\n",c);
	return a/b/c;
  }
int main()
{  int a,b;
printf("C(  ,  )");
scanf("%d%d",&a,&b); 
printf("%d",C(a,b));
}

