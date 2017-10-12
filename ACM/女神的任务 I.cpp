#include<stdio.h>
int main()
{
   int n,m,i,j,g,z;//i列 j行 n人数 m项目 g每人过的科目数 
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
