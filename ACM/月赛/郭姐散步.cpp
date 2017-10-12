#include<stdio.h>
#include<string.h>


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		int ans=0;
		int u=1,l=0,r=0;
		int uu,ll,rr;
		scanf("%d",&n); 
		for(int i=0;i<n;i++)
		 {
		 	uu=u+r+l;
		    rr=u+r;
		    ll=u+l;
		    u=uu;
		    r=rr;
		    l=ll;
		  }  
		  printf("%d\n",u+r+l);
		  
	}
}		            
		
		
		
