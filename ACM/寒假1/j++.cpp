#include<stdio.h>
#include<string.h>
int m,n;
char s[100][100];
void tobig(char s[],int a)
{
	int i;
	for(i=0;i<a;i++)
	 {
	 	if(s[i]>96) s[i]-=32;
	 }
}


void nnd(int a,int b,char ss[],int len)
{
	int f=1,i,j,ij[2],ii,aa,bb,jj;//ii ij¡¾ii¡¿ aa bb jj±È½Ï  
    m=100;n=100;
     
   
     
     f=1;
	for(i=0;i<a;i++)//ÓÒ 
	  {
	     for(j=0;j<b;j++)
	   {
	   	  f=1;
	  	  for(aa=i,bb=j,jj=0;jj<len&&bb<b;jj++,bb++)
	  	   if(ss[jj]!=s[aa][bb] ){f=0;break;}
	  	  if(f)break;
		  
	   }
	   if(f)break;
     }
     printf("%d %d\n",i,j);
     
	     n=j;m=i;
	 
      printf("%d %d\n",m,n);
 
     

	
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		
	   
	   int a,b,i,c;
	   char ss[100][100];
	   
	   scanf("%d%d",&a,&b);
	   for(i=0;i<a;i++)
	    scanf("%s",&s[i]);
	   for(i=0;i<a;i++)
	    tobig(s[i],b);
	    
	   scanf("%d",&c);
	   for(i=0;i<c;i++)
	    scanf("%s",&ss[i]);
	   for(i=0;i<c;i++)
	    tobig(ss[i],strlen(ss[i]));
	    
	    
	   for(i=0;i<c;i++)
	    {
	    	printf("%s | %d  | %d  |  %s  |  %d\n",s,a,b,ss[i],strlen(ss[i]));
	    	
		nnd(a,b,ss[i],strlen(ss[i]));
		
		printf("%d %d\n",m,n);
	    }
		 
	    printf("\n");
	   
	}
	return 0;
 } 
