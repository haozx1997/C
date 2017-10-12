#include<stdio.h>
#include<string.h>
long long er[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,
524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,
536870912,1073741824,2147483648,4294967296};

int sg[10010];
int vis[10010];
void sg_solve()
{
	int i,j;
	memset(sg,0,sizeof(sg));
	for( i = 0;i <= 100; i++ )
	{
		memset(vis,0,sizeof(vis));
		for(j = 0; j < 30; j++)
		{
			if(i >= er[j])
			 {
			 	vis[sg[i - er[j]]] = 1;
			 }
		}
		for( j = 0; j < 100; j++)
		{
			if(vis[j] == 0)
			 break;
		}
		sg[i] = j;
		printf("%d %d\n",i,sg[i]);
	}
	
	
}

int main()
{
	sg_solve();
//	int n;
//	while(~scanf("%d",&n))
//	{
//		if(n%3)
//		 printf("Kiki\n");
//		else
//		 printf("Cici\n"); 
//	}
}
