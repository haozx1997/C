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
	m=100;n=100;
	int f=1,i,j,ij[2],ii,aa,bb,jj;//ii ij【ii】 aa bb jj比较  
	for(i=0;i<a;i++)//上 
	 {
	  for(j=0;j<b;j++)
	   {
	   	  f=1;
	  	  for(aa=i,bb=j,jj=0;jj<len&&aa>=0;jj++,aa--)
	  	   if(ss[jj]!=s[aa][bb] ){f=0;break;}
	  	  if(f)break;
		  
	   }
	   if(f)break;
     }
     if(f&&jj==len){m=i;n=j;}
     else {m=100;n=100;}
     
     
     
    f=1;
	for(i=0;i<a;i++)//右上 
	  {
	     for(j=0;j<b;j++)
	   {
	   	  f=1;
	  	  for(aa=i,bb=j,jj=0;jj<len&&aa>=0&&bb<b;jj++,aa--,bb++)
	  	   if(ss[jj]!=s[aa][bb] ){f=0;break;}
	  	  if(f)break;
		  
	   }
	   if(f)break;
     }
    if(f&&jj==len)
     {
	  if(m>i||(m==i&&n>j)){m=i;n=j;}}
	
     
     
     f=1;
	for(i=0;i<a;i++)//右 
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
     if(f&&jj==len)if(m>i||(m==i&&n>j)){m=i;n=j;}
     
      
     f=1;
     for(i=0;i<a;i++)//右 下 
	  {
	     for(j=0;j<b;j++)
	   {
	   	  f=1;
	  	  for(aa=i,bb=j,jj=0;jj<len&&bb<b&&aa<a;aa++,jj++,bb++)
	  	   if(ss[jj]!=s[aa][bb] ){f=0;break;}
	  	  if(f)break;
		  
	   }
	   if(f)break;
     }
     if(f&&jj==len)if(m>i||(m==i&&n>j)){m=i;n=j;}
     
     
     
     f=1;
     for(i=0;i<a;i++)//下 
	  {
	     for(j=0;j<b;j++)
	   {
	   	  f=1;
	  	  for(aa=i,bb=j,jj=0;jj<len&&aa<a;jj++,aa++)
	  	   if(ss[jj]!=s[aa][bb] ){f=0;break;}
	  	  if(f)break;
		  
	   }
	   if(f)break;
     }
     if(f&&jj==len)if(m>i||(m==i&&n>j)){m=i;n=j;}
     
    
     
     
     f=1;
          for(i=0;i<a;i++)//左下 
	  {
	     for(j=0;j<b;j++)
	   {
	   	  f=1;
	  	  for(aa=i,bb=j,jj=0;jj<len&&aa<a&&bb>=0;jj++,bb--,aa++)
	  	   if(ss[jj]!=s[aa][bb] ){f=0;break;}
	  	  if(f)break;
		  
	   }
	   if(f)break;
     }
     if(f&&jj==len)if(m>i||(m==i&&n>j)){m=i;n=j;}
          
          f=1;
          for(i=0;i<a;i++)//左
	  {
	     for(j=0;j<b;j++)
	   {
	   	  f=1;
	  	  for(aa=i,bb=j,jj=0;jj<len&&bb>=0;jj++,bb--)
	  	   if(ss[jj]!=s[aa][bb] ){f=0;break;}
	  	  if(f)break;
		  
	   }
	   if(f)break;
     }
     if(f&&jj==len)if(m>i||(m==i&&n>j)){m=i;n=j;}
     
         
          f=1;
          for(i=0;i<a;i++)//左上 
	  {
	     for(j=0;j<b;j++)
	   {
	   	f=1;
	  	  for(aa=i,bb=j,jj=0;jj<len&&bb>=0&&aa>=0;aa++,jj++,bb--)
	  	   if(ss[jj]!=s[aa][bb] ){f=0;break;}
	  	  if(f)break;
		  
	   }
	   if(f)break;
     }
     if(f&&jj==len)if(m>i||(m==i&&n>j)){m=i;n=j;}
     
     printf("%d %d\n",m+1,n+1);
     
	
}

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		
	   getchar();
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
	    	
		nnd(a,b,ss[i],strlen(ss[i]));
		
	    }
		 
	    printf("\n");
	   
	}
	return 0;
 } 
