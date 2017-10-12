#include<stdio.h>
#include<string.h>

int N;
int t1[50];
int t2[50];
int w1[50];
int w2[50];
int I = 0;
int ans[50][50];
int ansi[50];
int max = 0;
int fun(int d,int *q1,int *q2,int a)
{
//	printf("i%d\n",d);
	if(d == 0) return 0;
	
	d--;
//	printf("         !!%d!!   **%d\n",q1[0],a);
	ans[a][ansi[a]++] = q1[0];
	int i ;
	for(i = 0 ;i < d;i++)
	{
		
		if(q2[i] == q1[0])
		{
			break;
		}
	}
	for(int j = 0;j < i;j++)//复制左子树数组 
	{
		w1[j] = q1[j+1];
//		printf("%d ",w1[j]);
	}
//	printf("\n"); 
	for(int j = 0;j < i;j++)
	{
		w2[j] = q2[j];
//		printf("%d ",w2[j]);
	}
//	printf("\n");
//	printf("!!!%d\n",i);
//	for(int j = 0;j < i;j++)
//	{
//		
//		printf("w1 %d ",w1[j]);
//	}
//		for(int j = 0;j < i;j++)
//	{
//		
//		printf("w2 %d ",w2[j]);
//	}

	fun(i,w1,w2,a+1);	
	int ii = d - i;
//	printf("%d\n",ii); 
	for(int j = 0;j < ii;j++)
	{
		w1[j] = q1[j+i+1];
//		printf("%d ",w1[j]);
	}
//	printf("\n");
	for(int j = 0;j < ii;j++)
	{
		w2[j] = q2[j+i+1];
//		printf("%d ",w2[j]);
	}
	
//	printf("\n@\n");
	
	fun(ii,w1,w2,a+1);
	a>max ? max = a:max = max;
}




int main()
{
	
	while(~scanf("%d",&N))
	{
		memset(ans,0,sizeof(ans));
		memset(ansi,0,sizeof(ansi));
		
		for(int i = 0;i < N;i++)
		{
			scanf("%d",&t1[i]);	//中 
		}
		
		for(int i = 0;i < N;i++)
		{
			scanf("%d",&t2[i]);	//	前 
		}
		fun(N,t2,t1,I);
		for(int i = 0 ;i < max;i++)
		{
			for(int j = ansi[i] - 1;j >= 0;j--)
			{
				printf("%d ",ans[i][j]);
			}
		}
		
		for(int j = ansi[max]-1;j > 0;j-- )
		{
			printf("%d ",ans[max][j]);
		}
		printf("%d",ans[max][0]);
	}
 } 
