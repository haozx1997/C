#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m,n,c,d,e;
	printf("输入两个数用,隔开\n") ;
	scanf("%d,%d",&m,&n);
	if(m>n)
	    c=m,m=n,n=c;
    d=n;
    while(m%d||n%d)
	    d--;
        printf("最大公因数%d\n",d);
    e=n;
    while(e%m||e%n)
	    e++;
        printf("最小公倍数%d\n",e); 
    system("pause");
	return 0;
}
