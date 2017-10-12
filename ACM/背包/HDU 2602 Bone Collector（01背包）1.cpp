#include<stdio.h>  
#include<string.h>  
#define M 1009  
typedef struct pack  
{  
    int cost;  
    int val;  
}PACK;  
int f[M][M];
/*

1
5 10
1 2 3 4 5
5 4 3 2 1

2
6 29 
9 3 6 7 10 15
10 4 5 20 9 11



9 10
3 4
6 5
7 20
10 9
15 11


*/  
int main()  
{  
    int cas,n,v,i,j;  
  
    PACK a[M];  
    scanf("%d",&cas);  
    while(cas--)  
    {  
        scanf("%d%d",&n,&v);  
        memset(f,0,sizeof(f));  
        for(i=1;i<=n;i++)  
            scanf("%d",&a[i].val);  
        for(i=1;i<=n;i++)  
            scanf("%d",&a[i].cost);  
        for(i=1;i<=n;i++)  
            for(j=0;j<=v;j++)  
                {if(j-a[i].cost>=0&&f[i-1][j]<f[i-1][j-a[i].cost]+a[i].val)  
                    f[i][j]=f[i-1][j-a[i].cost]+a[i].val;  
                else  
                    f[i][j]=f[i-1][j];  
                    printf("!!%d %d %d\n",i,j,f[i][j]);  
				}
        for(int i = 1;i<=n;i++)
		{
			for(int j = 0;j<v;j++)
			{
				printf("%d ",f[i][j]);
			}
			printf("\n");
			
		}
		            
        printf("%d\n",f[n][v]);  
    }  
    return 0;  
}   
