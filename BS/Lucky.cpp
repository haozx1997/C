#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int f=0;
		int n;
		scanf("%d",&n);
		int all=n;
		int a[10000];
		for(int i=0;i<n;i++)
		 {
		 	scanf("%d",&a[i]);
			
		 }
		for(int i=0;i<n-1;i++)
		 {
		 	for(int j=i;j<n;j++)
		 	 {
		 	 	if((a[i]-a[j])==1||(a[i]-a[j])==-1)
		 	 	 {
		 	 	 	f=1;
		 	 	 	break;
				   } 
				  a[all++]= a[i]-a[j];
			  }
			  if(f) break;
		  }
		  if(f)printf("YES\n");
		  else printf("NO\n"); 
	}
 } 
