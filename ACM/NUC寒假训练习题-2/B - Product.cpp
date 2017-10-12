#include<stdio.h>
#include<string.h>

int len,lenn,i,alen,blen,j,ei;
char a[1005],b[1005],c[1005],d[1005],e[1005],f[1005],t;

void xxx(char x1[],int x2)
{
	for(i=0;i<len;i++)
	 {
	 	e[i]=0;
	 }
	for(i=0;i<len;i++)
	{
		e[i]+=x1[i]*x2;
		if(e[i]>9)
		 {
		 	e[i+1]=e[i]/10;
		 	e[i]-=(e[i+1])*10;
		 }
	 } 
}

int jjj(char jj[])
{
	for(i=0;i<=1000;i++)
	 {
	 	f[i]+=e[i];
	 	if(f[i]>9)
	 	 {
	 	 	f[i]-=10;
	 	 	f[i+1]++;
		  }
	 }
}
int main()
{

	
	while(scanf("%s%s",a,b)!=EOF)
	{
	    int F=0;
	    
		alen=strlen(a);blen=strlen(b);
		for(i=0;i<(alen+1)/2;i++)
		 {t=a[i];a[i]=a[alen-1-i];a[alen-1-i]=t;} 
		for(i=0;i<(blen+1)/2;i++)
		 {t=b[i];b[i]=b[blen-1-i];b[blen-1-i]=t;} 
		if(alen>blen)
		 {
		   for(i=0;i<alen;i++)
		    c[i]=a[i];
		    for(i=0;i<blen;i++)
		    d[i]=b[i];
		    len=alen;lenn=blen;
         }
		else 
		 {
		   for(i=0;i<blen;i++)
		    c[i]=b[i];
		    for(i=0;i<alen;i++) 
		    d[i]=a[i];
		    len=blen;lenn=alen;
	     } 
		for(i=0;i<len;i++)
		  {
		  	c[i]=c[i]-'0';
		  	if(c[i]==0) F++;
		  }
		if(F==len) 
		{
			printf("0\n");
			continue;
		  }  
		  F=0;
		for(i=0;i<lenn;i++)
		  {
		  	d[i]=d[i]-'0'; 
		  	if(d[i]==0) F++;
		   } 
		   if(F==lenn) 
		   {
			printf("0\n");
			continue;
		  } 
		
		for(i=0;i<1005;i++)
		 {
		 	f[i]=0;
		 	
		  } 
		for(j=0;j<lenn;j++)
		{
			for(i=0;i<1005;i++)
			
			   e[i]=0;
			xxx(c,d[j]);
			for(ei=len;ei>=0;ei--)
			 e[ei+j]=e[ei];
			
			for(ei=j;ei>=0;ei--)
			 e[ei-1]=0; 
			
			jjj(e);
		}
		for(i=1000;i>=0;i--)
		 if(f[i])
		  {
		  	for(;i>=0;i--)
		  	printf("%d",f[i]);
		  	break;
		  }
		
		   
	    printf("\n"); 
	    
	}
    return 0;
 } 
