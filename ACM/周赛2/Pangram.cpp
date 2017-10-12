#include<stdio.h>
#include<string.h>
 
 
int main()
{
	int n;
	int i,sum;
	char s[105];
	int  az[30];
	while(scanf("%d",&n)!=EOF)
	 {
	 	sum=0;
	 	memset(az,0,sizeof(az));

		scanf("%s",s);
	 	if(n<26)
	 	{
	 		printf("NO\n");
	 		continue;
		 }		
		for(i=0;i<n;i++)
		{
			if(s[i]>'Z') s[i]-=32;
		
			az[s[i]-64]=1;
		}
		 for(i=0;i<30;i++)
		 {
		 
		 	sum+=az[i];
		 }
		 if(sum==26)printf("YES\n");
		 else printf("NO\n");
		 
	 }
	
 } 
