#include<stdio.h>
int main()
{
 
	while(1)
	{
		char chi[1005],F=1;
	int i1,i,j,t;
	long long a[1005];
	
	for(j=0;F;j++)
	{
		i=0;
		for(;;i++)
		{
			
		    if((chi[i]=getchar())=='5') { break;}
			if(chi[i]=='\n'){ F=0;break;}
		}
		for(i1=1,a[j]=chi[0]-'0';i1<i;i1++)
	      a[j]=a[j]*10+(chi[i1]-'0');
    }

	 
	int n,m,min;
	for(n=0;n<j-2;n++)
	{
		min=n;
		for(m=n+1;m<j-1;m++)
		 if(a[min]>a[m]) min=m;
		if(min!=n)
		{
			t=a[min];a[min]=a[n];a[n]=t;
		 } 
	}

	 for(i=0;i<j-1;i++)
	 if((a[i]!=-48)&&(a[i]!=5))
	 {
	 	if(i<j-2)printf("%d ",a[i]);
	 	else printf("%d",a[i]);
	 }
	 printf("\n");
	 
	 
	}
	
	
 } 
