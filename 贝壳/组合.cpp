#include<stdio.h>

long long A(long long  n)
  {
//	printf("%lld\n",n);
	if(n==1||n==0)
	 return 1;
	else
	 n=n*A(n-1);
	return n;
	
  }
long long   C(long long  n,long long  m)
  { 
    long long  a,b,c;
    a=A(n); 
//	printf("nn %d nn ",a);
    b=A(m); 
//	printf("mm %d mm",b);
    c=A(n-m); 
//	printf("n-m %d n-m\n",c);
	return a/b/c;
  }
int main()
{  long long  a = 1,b;

	printf("%lld\n",A(10));
	for(int i = 20; i > 0;i -= 2)
	{
	
		a*=C(i,2);
			printf("%lld\n",a);
		if(i == 10)
		{
			a/=A(10);
		}
		
	 } 
	
}

