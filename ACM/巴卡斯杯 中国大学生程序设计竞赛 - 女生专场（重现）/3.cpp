#include<stdio.h>

int n;
int num[200];

double ave()
{
	int s=0;
	for(int i = 0 ;i<n;i++)
	{
		s+=num[i];
	}
	return s/(double)n;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(int i = 0;i<n-1;i++)
		{
			scanf("%d",&num[i]);
		}
		int i;
		for(i = 0;;i++)
		{
			num[n-1] = i;
			double a =ave();
			if(i>(a*2/3))
			{
				
				break;
			}
		}
		int all=1;
			
		for(int j = 0;j<n-1;j++)
		{
			
			if(num[j]==(i-1)) all++;
		}
		
		printf("%d %.2f\n",i-1,1/(double)all);
		
	}
	
 } 
