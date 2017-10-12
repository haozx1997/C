#include<iostream>  
#include<cstdio>  
#include<cstring>  
using namespace std;  
int dp[100005];  
bool path[105][10005];  
int c[10005],w[10005];  
int out[10005];

int main()  
{  
    int T,TT = 1;
    
    int N,V;
	scanf("%d",&T);
	while(T--) 
    {  
    	int outn = 0;
    	scanf("%d%d",&V,&N);
		int vv[1010],w[1010];
		for(int i = 1;i<=N;i++)
		{
			scanf("%d%d",&w[i],&c[i]);
		}
        memset(path,0,sizeof(path));  
        memset(dp,0,sizeof(dp));  
        
        for (int i = 1;i <= N;++i)  
      //  for (int i = N;i >= 1;--i)  
        
        {  
            for (int j = V;j >= c[i];--j)  
            {  
                if (dp[j] < dp[j-c[i]]+w[i])  
                {  
                    dp[j] = dp[j-c[i]]+w[i];  
                    path[i][j] = 1;  
                }  
            }  
        }  
//         for(int i = 1; i<=N;i++)
//         {
//         	for(int j =1;j <= V;j++)
//         	{
//         		printf("%d ",path[i][j]);
//			 }
//			 puts("");
//		 }
        
        for (int i = N,j = V;i >= 1&&j > 0;i--)  
        {  
            if (path[i][j])  
            {  
      //      	printf("%d %d\n",i,j);
                out[outn++] = i;  
                j -= c[i];  
            }  
        }  
        printf("Case #%d:\n",TT++);
        int ans2 = 0;
        for(int i = 0;i < outn;i++)
		{
			ans2 += c[out[i]];
		 }
		printf("%d %d\n",dp[V],ans2);
		if(outn)
		{
			printf("%d",out[outn-1]);
			for(int i = outn-2;i >=0 ;i--)
			{
				printf(" %d",out[i]);
			}
			puts("");
		  }  
    }  
    
    
    
    /*
	3
29
6
9 10
3 4
6 5
7 20
10 9
15 11
0
2
2 23
10 12



3
6
1 1
1 1
1 1
1 1
1 1
1 1

10

2
29
6
9 10
3 4
6 5
7 20
10 9
15 11
Case #1:
34 29
2 3 5 6
0
2
2 23
10 12
Case #2:
0 0


	
	
	*/
    
    return 0;  
}  
