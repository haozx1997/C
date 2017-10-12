#include<stdio.h>
main()
{ //求一个4*4方阵中对角线元素之和//
	int a[4][4],i,j,s;

	for(i=0;i<4;i++)
	   for(j=0;j<4;j++)
	   scanf("%d",&a[i][j]);
	
	for(s=0,i=0,j=0;i<4;i++,j++)
	    s=s+a[i][j];
	printf("主对角线=%d\n",s);
	for(s=0,i=3,j=0;j<4;i--,j++)
	    s=s+a[i][j];
	printf("次对角线=%d",s);
	
	return 0;
 } 
