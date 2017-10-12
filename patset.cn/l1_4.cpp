#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;
int main()

{
	int n;
	int fr[200][1010];
	int ask,ask_n;
	int askall[10010];
	int nn[200];
	int all = 0;
	scanf("%d",&n);
	for(int I = 0;I<n;I++)
	{
		
		scanf("%d",&nn[I]);
		for(int i = 0; i<nn[I];i++)
		{
			scanf("%d",&fr[I][i]);
		}
		
		
	}int space = 0;
	
	scanf("%d",&ask);
	for(int i = 0;i<ask;i++)
	{
		int F = 0;
		scanf("%d",&ask_n);
		askall[i] = ask_n;
		for(int ii=0;ii<n;ii++)
		{
			for(int jj = 0;jj<nn[ii];jj++)
			{
				if(fr[ii][jj]==ask_n&&nn[ii]!=1)
				{
					F = 1;
					break;
				}
			}
			if(F)
			{
				break;
			}
		}
		
		int ff= 0;
		if(F)
		{
			continue;
		}
		
		else
		{
			for(int qwe = 0;qwe<i;qwe++)
				{
					if(ask_n == askall[qwe])
					{
						ff= 1;
						break;
					}
					
				}
			if(ff)
			{
				continue;
			}
			if(space)
			{
				printf(" ");
			}
			printf("%d",ask_n);
			all = 1;
			space = 1;
		}
		
		
	}
	if(!all)
		{
			printf("No one is handsome\n");
		}

	

}
