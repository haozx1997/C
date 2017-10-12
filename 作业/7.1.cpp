#include<stdio.h>
#include<string.h>
main()
{   //有一个已经排好序的数组a[10] = {2, 13, 25, 31, 56, 67, 80, 94, 111}。现输入一个数，将该数插入数组中使数组仍然有序。//
	int a[10]={2,13,25,31,56,67,80,94,111},i,j,x;
	scanf("%d",&x);
	for(i=0;x>a[i];i++);
	for(j=9;j<i;j--)
	    a[j]=a[j-1];
	a[i]=x;
	for(i=0;i<10;i++)
	    printf("%d ",a[i]);
	return 0;	
 } 
