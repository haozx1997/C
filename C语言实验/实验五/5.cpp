#include<stdio.h>
int main()
{//��һ������һ��һά������ɾ����
	int a[10],i,j,k,t,x;
	printf("please input a:");
	for(i=0;i<10;i++)
	 scanf("%d",&a[i]);
	printf("please input x:");
	 scanf("%d",&x);
	for(i=0;i<10;i++)
	  {
		if(a[i]==x)
		 {
		 for(;i<9;i++)
		  a[i]=a[i+1];
	     }
	  }
	for(i=0;i<9;i++)
	 printf("%d ",a[i]);
	return 0 ;
}
