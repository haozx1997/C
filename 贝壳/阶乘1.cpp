#include<stdio.h>
long jc(int a,int n)
{
	int i=1,b=1;
	for(;i<=n;i++)
	 b=b*a;
	 return b;
}
int main()
{
     int s,t,z=0,i,m,n;//sǰ���� t����� z��ֵ  iλ�� n ÿ������asc m ÿλ����ֵ 
     
     for(i=0;(n=getchar())!=' ';i++) 
         {
            if(n<58) m=n-'0';
		    else m=n-55 ;
		    z=z+(jc(10,i))*m;
			printf("%d ",m);
	     }
	     printf("%d",z);
	  
	  
     
	 
}
