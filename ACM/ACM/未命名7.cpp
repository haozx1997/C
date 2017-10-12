#include<stdio.h>
int main()
{
	int a[10]={1,2,3,4,5,6,7,8,9,0},a1[7],t,y,b[3],c[3],d[4],i,j;
    scanf("%d",&t);
	while(t--)
	{
	  scanf("%d",&y);
	  b[0]=y/100;
	  b[1]=y%100/10;
	  b[2]=y%10;
	  for(i=0,j=0;i<10;i++)
	   {
	   	 if(a[i]==b[0]||a[i]==b[1]||a[i]==b[2]) continue;
	   	 a1[j]=a[i];
	   	 j++;
	   }
	   for(j=0;j<7;j++)
	    printf("%d ",a1[j]);
	 } 
	    
	return 0 ;
 } 
