#include<stdio.h>
#include<string.h>
int main()
{
	char chi[1005],F=1;
    int i1,i,ii,j,t;
	long long a[1005];
	while(scanf("%s",chi)!=EOF)
	{
		F=1;j=0;
			i=0;
		while(F)
		{
			
		    ii=i;
		    for(;i<strlen(chi);i++)
		  {
			if(chi[i]=='5') { break;}
			if(i=strlen(chi)-1){ F=0;break;}
		  }
		  for(i1=ii+1,a[j]=chi[ii]-'0';i1<i;i1++)
	        a[j]=a[j]*10+(chi[i1]-'0');
	        j++;
         
		}
         printf("%s\n",chi);
         for(i=0;i<j;i++)
          printf("%d !%d",a[i],j);
	
	
	
	

	 
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
	
	return 0;
 } 
