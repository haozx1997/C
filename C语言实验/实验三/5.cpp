#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m,n,c,d,e;
	printf("������������,����\n") ;
	scanf("%d,%d",&m,&n);
	if(m>n)
	    c=m,m=n,n=c;
    d=n;
    while(m%d||n%d)
	    d--;
        printf("�������%d\n",d);
    e=n;
    while(e%m||e%n)
	    e++;
        printf("��С������%d\n",e); 
    system("pause");
	return 0;
}
