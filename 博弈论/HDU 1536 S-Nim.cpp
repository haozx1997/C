#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
using namespace std;
 
const int N = 100;
int sg[N];
bool vis[N];
void sg_solve(int *s,int t,int N)   //N求解范围 S[]数组是可以每次取的值，t是s的长度。  
{  
	
    int i,j;  
    memset(sg,0,sizeof(sg));  
    for(i=1;i<=N;i++)  
    {  
        memset(vis,0,sizeof(vis));  
        for(j=0;j<t;j++)  
            if(i >= s[j] )  
                vis[sg[i-s[j]]] = 1;  
        for(j=0;j<=N;j++)  
            if(vis[j] == 0)  
                break;  
        sg[i] = j;
		printf("%d %d\n",i,sg[i]);  
    }  
}  

int main()
{
	int n;
	while(scanf("%d",&n),n)
	{
		int a[110];
		for(int i = 0; i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		sg_solve(a,n,N);
		int qn;
		scanf("%d",&qn);
		while(qn--)
		{
			int nn;
			int m[110];
			scanf("%d",&nn);
			for(int i = 0 ;i < nn;i++)
			{
				scanf("%d",&m[i]);
			}
			int ans = 0;
			for(int i = 0 ;i < nn;i++)
			{
				ans ^= sg[m[i]];
			}
			
			printf("%c","LW"[ans != 0]);
		}
		printf("\n");
	}
  }  
