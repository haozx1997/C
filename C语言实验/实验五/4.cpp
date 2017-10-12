#include<stdio.h>
int main()
{ //有一个已经排好序的数组。现输入一个数，要求按原来的规律将它插入数组中 
	int a[10]={11,22,33,44,55,66,77,88,99};
	int n,i,j,k,t;
	scanf("%d",&n);
	a[9]=n;
	for(i=0;i<10;i++) // 重排 
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
	 
	
