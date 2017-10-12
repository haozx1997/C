#include "stdio.h" 
main ()
{
	char a;
	a='0';
    printf("%c 10:%d 8:%o 16:%x\n",a,a,a,a);
    a='9';
    printf("%c 10:%d 8:%o 16:%x\n",a,a,a,a);
    a='A';
    printf("%c 10:%d 8:%o 16:%x\n",a,a,a,a);
    a='Z';
    printf("%c 10:%d 8:%o 16:%x\n",a,a,a,a);
    a='a';
    printf("%c 10:%d 8:%o 16:%x\n",a,a,a,a);
    a='z';
    printf("%c 10:%d 8:%o 16:%x\n",a,a,a,a);
}
