#include<stdio.h>
int main()
{// ����n��������ʹ��ָ���������n��������С�������������
	int a[10],i,j,*p,t;
	for (i=0;i<10;i++)
	 scanf("%d",&a[i]);
	p=a;
	for(i=0;i<10;i++)
	 {
	 	for(j=0;j<10;j++)
	 	if(a[j]>a[j+1])
	 	 {
	 	 	t=a[j];
	 	 	a[j]=a[j+1];
	 	 	a[j+1]=t;
		  }
	 }
	for (i=0;i<10;i++)
	printf("%d ",*(p+i));
	return 0;
 } 
