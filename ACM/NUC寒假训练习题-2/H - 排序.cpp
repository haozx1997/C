#include<stdio.h>
int main()
{
	int N;
	while(1)
	{
		char chi[1005],ch[1005][1004],F=1;
	int i,j,ii,jj,a[1005],chii[1005],t;//jj×ÜÊý 
	
	for(j=0;F;j++)
	{
		i=0;
		for(;;i++)
		{
			
			if((chi[i]=getchar())=='5') break;
			if(chi[i]=='\n'){ F=0;break;}
			
		}
		for(ii=0;ii<i;ii++)
		 ch[j][ii]=chi[ii];
		chii[j]=i; 
	}

	 for(jj=0;jj<j-1;jj++)
	{
		for(i=1,a[jj]=ch[jj][0]-'0';i<chii[jj];i++)
	{
		a[jj]=a[jj]*10+(ch[jj][i]-'0');

	}
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

	 for(jj=0;jj<j-1;jj++)
	 if(a[jj]!=-48)
	 {
	 	if(jj<j-2)printf("%d ",a[jj]);
	 	else printf("%d",a[jj]);
	 }
	 printf("\n");
	 
	 
	}
	
	
 } 
