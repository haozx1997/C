#include<stdio.h>
#include<string.h>

int main()
{
	char a[1005],b[1005],c[1005],d[1005];
	int n,T=1;
	scanf("%d",&n);
	getchar();
	while(n--)
	{
		int len,lenn,i,alen,blen,t;
		scanf("%s%s",a,b);
		printf("Case %d:\n%s + %s = ",T++,a,b);
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
		for(i=0;i<lenn;i++)
		  c[i]=c[i]+d[i]-'0';
		c[len]='0';  
		for(i=0;i<len;i++)
		 if(c[i]>'9')
		  {
		    c[i]=c[i]-10;
			c[i+1]++;	
		   }  
		
		 if(c[len]!='0') 
		    for(i=len;i>=0;i--)
		     printf("%c",c[i]);
		 else 
		    for(i=len-1;i>=0;i--)
		     printf("%c",c[i]);
	    printf("\n"); 
		if(n)      
		printf("\n"); 
	}
    return 0;
 } 
