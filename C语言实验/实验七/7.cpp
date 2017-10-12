#include<stdio.h>
int main()
{ 
    printf("¿ÕNND¸ñ£¬±ð¿Õ\n");
	int n,a[10]={0};
	for(;(n=getchar())!='\n';)
	 {
	   a[n-'0']++;
     }
	for(n=0;n<10;n++)
       printf("%d: %d\n",n,a[n]);
	return 0;
}
