#include<stdio.h>

int main()
{
	int n;
	int a[1010];
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int F=0;
	int ans=0;
	if(a[0]>a[1]) F=1;
	for(int i=1;i<n-1;i++)
	{
		if(F) 
		{
			if(a[i]<a[i+1]) 
			
			{
				F=0;
				ans++;
			}
		}
		else
		{
			if(a[i]>a[i+1]) 
			
			{
				ans++;
				F=1;
			}
		}
		
	}
	printf("%d\n",ans);
	return 0;
	
}
