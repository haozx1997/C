#include<stdlib.h>
#include<stdio.h>
double num[10]={1.11,2.22,3.33,4.44,5.55,6.66,7.77,8.88,9.99,10.10101}; 



int cmp ( const void *a , const void *b ) 
{ 
return *(double *)b>*(double *)a?1:-1; 
} 
int main()
{
	int i;
	for(i=0;i<10;i++)
	printf("%f ",num[i]);
	printf("\n");
	qsort(num,10,sizeof(num[0]),cmp);
	
	for(i=0;i<10;i++)
	printf("%f ",num[i]);
}
