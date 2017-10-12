#include<stdio.h>
#include<string.h>

int N;
char t1[50];
char t2[50];
char w1[50];
char w2[50];
int I = 0;
char ans[50][50];
int ansi[50];
int max = 0;
int fun(int d,char *q1,char *q2,int a)
{
//	printf("i%d\n",d);
	if(d == 0) return 0;
	
	d--;
	long qqqqq = q1[0];
//	printf("         !!%c!!   **%d\n",q1[0],a);
	ans[a][ansi[a]++] = q1[0];
	int i ;
	for(i = 0 ;i < d;i++)
	{
		
		if(q2[i] == q1[0])
		{
			break;
		}
	}

	for(int j = 0;j < i;j++)//复制all左子树数组 
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
	if(i == 0) 
	{
//		printf(" %c   %d\n",w1[0],a+1);
	}
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
	printf("%c",qqqqq);
}




int main()
{
	
	
		memset(ans,0,sizeof(ans));
		memset(ansi,0,sizeof(ansi));
		
		
		scanf("%s",t1);	// 
		
		
		scanf("%s",t2);	// 
		N = strlen(t1);
		fun(N,t1,t2,I);// 前 中
//		for(int i = 0 ;i <= max;i++)
//		{
//			for(int j = 0;j < ansi[i];j++)
//			{
//				printf("%c",ans[i][j]);
//			}
//		}
		
		
	}
 
