#include <stdio.h>
int max(int a,int b)
{
	int c,d;
	if(a>b)
	       c=a,a=b,b=c;
    d=b;
    while(a%d||b%d)
	     d--;
    return d;
}
int min(int a,int b)
{
	int c,d;
	if(a>b)
	       c=a,a=b,b=c;
    d=b;
    while(d%a||d%b)
	     d++;
    return d;
}
main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("最大公因数=%d\n最小公倍数=%d",max(a,b),min(a,b));
	return 0;
}
