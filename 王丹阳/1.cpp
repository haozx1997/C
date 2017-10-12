#include<stdio.h>
int z[10000];
void fun(int m,int k,int *xx)
{
	int i;
	for(i = 0;;i++)
	{
		if(z[i]>m) 
		{
			
			break;
			
		}
	}
	int ii = 0;
	for(int j = i;j<i+k;j++)
	{
		xx[ii++] = z[j];
		
	}
}

void zz()
{
	int a,b,i=0,n;
	
	int ifz[10000];//ÅÐ¶ÏÊÇ·ñËØÊý 
	for(a=2;a<10000;a++)
	  {
		for(b=2;b<a;b++)
		  {
		  	if((a%b)==0) break;
		  };
		if(b==a)
		  {
		  	z[i]=a;
 	        ifz[z[i]]=1;
		  	i++;
		  } ;
	  }  
}

int main()
{
	int a,b;
	zz();
	scanf("%d%d",&a,&b);
	int aa[10];
	fun(a,b,aa);
	for(int i = 0;i<b;i++)
	{
		printf("%d\n",aa[i]);
	}
 } 
