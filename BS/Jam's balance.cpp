#include<stdio.h>
int main()
{
	int T,n[21],i,j,m,q,w,f;
	int ii,jj,sum;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&i);//Ì¿¬Î 
		for(j=0;j<i;j++)
		 scanf("%d",&n[j]);
		scanf("%d",&m); 
		for(q=0;q<m;q++)
		 {
		 	f=0;sum=0;
		 	scanf("%d",&w);//≥∆m ii jj
		 	for(ii=i-1;ii>=0;ii--)
			 {
			 	for(jj==ii;jj>=0;jj--)
			     {
			   	   sum+=n[jj];
				 } 
			  if(sum==w){f=1;break;}
		     }
			
			if(f) printf("YES\n");
		    else  printf("NO\n");  
		 }
		 
	}
	return 0;
 } 
