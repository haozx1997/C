#include<stdio.h>
int main()
{
   int n,m,i,j,g,z;//i�� j�� n���� m��Ŀ gÿ�˹��Ŀ�Ŀ�� 
   while(scanf("%d%d",&n,&m)!= EOF,n&&m)
    {
    	int s[m];
    	for(i=0;i<m;i++)
    	 scanf("%d",&s[i]);
    	int t[n][m];
		for(j=0;j<n;j++)
		 for(i=0;i<m;i++)
		  {
		  	scanf("%d",&t[j][i]);
		   } 
	    for(j=0,z=0;j<n;j++)
		 {
		   for(i=0,g=0;i<m;i++)
		    {
		  	if(t[j][i]>=s[i]) g++;
		    }
		    if(g==m) z++;
		 }
		printf("%d",z);
		printf("\n");
	
	}
	 return 0;
}
