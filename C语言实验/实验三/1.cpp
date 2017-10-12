#include<stdio.h>
int main()
{//编程实现：求S = 3 + 33 + 333 + 3333 + 33333//
    double x; 
	int S,a,s;
    x=1.0/3;
    for(S=0,s=0,a=1;a<1000000;a=10*a)
        {
		s=(int)(a*x);
		S=S+s;
		};
	printf("S=%d",S);
	return 0;		
}
