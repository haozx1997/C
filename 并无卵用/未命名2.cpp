#include <stdio.h>
int main()
{

	int a=3,b=4,c,d;
	if(a>b)
	       c=a,a=b,b=c;
    
    d=a;
    while(d%a||d%b)
	     d++;
    printf("%d",d);
}

