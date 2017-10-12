#include<stdio.h>
int main()
{//编程实现：从键盘输入6个数（用一维数组保存），用起泡法对6个数按从大到小排序，并输出结果。运行结果示例如下：
	int a[6],i,j,k,t;
	printf("please input a:");
	for(i=0;i<6;i++)
	 scanf("%d",&a[i]);
	for(i=0;i<6;i++)
	 {
	 	for(j=i+1;j<6;j++)
	 	 {
	 	 	if(a[i]<a[j])  
			  {
			   t=a[i];a[i]=a[j];a[j]=t;
			  }

		 }
	 }
	 for(i=0;i<6;i++)
	 printf("%d ",a[i]);
    return 0 ;
} 
