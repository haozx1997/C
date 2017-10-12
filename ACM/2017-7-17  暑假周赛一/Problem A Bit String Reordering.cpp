#include<bits/stdc++.h>

using namespace std;


int n,m,a[100],a1[100],b0[100],b1[100],b;
int b0n,b0b,b1n,b1b;



int main()
{

	
	while(~scanf("%d %d",&n,&m))
	{
		int sum = 0;
		int sum0 = 0;
		int sum1 = 0;
		b0n = b0b = b1n = b1b = 0;
		b1b = 1;
		for(int i = 0;i < n;i++ )
		{
			scanf("%d",&a[i]);
			sum += a[i];
			a1[i] = a[i];
		}
		for(int i = 0;i < m;i++ )
		{
			scanf("%d",&b);
			for(int j = 0;j<b;j++)
			{
				b0[b0n++] = (b0b%2);
				sum0 += (b0b%2);
				b1[b1n++] = (b1b%2);
				sum1 += (b1b%2);
				
			}
			b0b++;b1b++;
			
		}
		int ans0 = 0;
		int ans1 = 0;
		int F = 0;
		/*
1 1 1 0 0 0 0
0 0 0 0 1 1 1
1 0 1 0 1 0 1 0 1 0 1 0 1 0 1
0 1 0 1 0 1 0 1 0 1 0 1 0 1 1 

*/
//		for(int i = 0; i < n;i++)
//		{
//			printf("%d ",a[i]);
//		}
//		puts("");
//		for(int i = 0; i < n;i++)
//		{
//			printf("%d ",b0[i]);
//		}
//		puts("");
//		for(int i = 0; i < n;i++)
//		{
//			printf("%d ",b1[i]);
//		}
//		puts("");
//		
		if(sum == sum0)
		{
			F += 1;
			for(int i = 0; i < n;i++)
			{
				if(b0[i]!=a1[i])
				{
					
					for(int j = i+1; j < n;j++)
					{
						if(a1[j] == b0[i])
						{
							ans0+=(j-i);
						//	printf("	%d\n",(j-i));
							a1[j] = a1[i];
							break;
						}
					}
				}
			}
		}
		if(sum == sum1)
		{
			F += 2;
			for(int i = 0; i < n;i++)
			{
				if(b1[i]!=a[i])
				{
					
					for(int j = i+1; j < n;j++)
					{
						if(a[j] == b1[i])
						{
							ans1+=(j-i);
						//	printf("	%d %d %d\n",i,j,(j-i));
							a[j] = a[i];
							break;
						}
					}
				}
			}
		}
	//	printf(" %d %d %d %d %d %d\n",F,sum,sum0,sum1,ans0,ans1);
		switch(F)
		{
			case 1:
				printf("%d\n",ans0);
				break;
			case 2:
				printf("%d\n",ans1);
				break;
			case 3:
				printf("%d\n",min(ans1,ans0));
				break;
				
		}
//		printf("%d %d %d %d %d",sum,sum0,sum1,ans0,ans1);
//		printf("%d\n",min(ans1,ans0));
//		for(int i = 0;i < n;i++ )
//		{
//			printf("%d %d\n",b0[i],b1[i]);
//		}
//		
	}



 return 0;
}


