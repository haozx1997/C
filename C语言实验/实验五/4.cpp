#include<stdio.h>
int main()
{ //��һ���Ѿ��ź�������顣������һ������Ҫ��ԭ���Ĺ��ɽ������������� 
	int a[10]={11,22,33,44,55,66,77,88,99};
	int n,i,j,k,t;
	scanf("%d",&n);
	a[9]=n;
	for(i=0;i<10;i++) // ���� 
     { k=i;
      for(j=i+1;j<10;j++)
        if(a[j]<a[k]) k=j;
           if(k!=i)
		    { t=a[i];a[i]=a[k];a[k]=t; }
     }
    for(i=0;i<10;i++)
	  printf("%d ",a[i]);
     return 0;
}
	 
	
