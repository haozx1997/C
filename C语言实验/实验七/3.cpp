//�Ӽ���Ϊ����a[4][4]�������ݣ��ֱ���ָ������Ԫ�ص�ָ�������ָ��һά�����ָ����������������Ԫ�أ��������ÿһ�е����ֵ������Щֵ������һά����b[4]��
#include<stdio.h>
int main()
{
	int a[4][4] ,b[4],i,j,t,max;
	int (*p)[4];
	for(i=0;i<4;i++)
	 for(j=0;j<4;j++)
	 scanf("%d",&a[i][j]);
	p=a;
	for(;p<a+4;p++)
	 {
	 	for(i=0;i<4;i++)
	 	  printf("%5d",*(*p+i));
	 	printf("\n");  
	 }
	for(p=a,j=0;p<a+4;j++,p++)
	{
		 for(i=0;i<3;i++)
	 	 {
	 	 	if(*(*p+i)>*(*p+i+1))
	 	 	  {
			   t=*(*p+i);
	 	 	   *(*p+i)=*(*p+i+1);
	 	 	   *(*p+i+1)=t;
	 	      }
		 }
		b[j]=*(*p+i);
	}
	 for(j=0;j<4;j++)
	 printf("%d",a[j]);
	 return 0;
}
