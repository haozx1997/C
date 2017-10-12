#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

long long c1[1005],c2[1005],c3[1000];
int d[1005][1005];
int main()
{
	int n1,n2;
	scanf("%d",&n1);
	for(int i = 0;i < n1;i++)
	{
		scanf("%lld",&c1[i]);
		
	}
	
	scanf("%d",&n2);
	for(int i = 0;i < n2;i++)
	{
		scanf("%lld",&c2[i]);
		
	}
	
    
        int i,j,s,t,k;
        memset(d,0,sizeof(d));
        for(i=0;i<=n1;i++)
            d[i][0]=0;
        for(j=0;j<=n2;j++)
            d[0][j]=0;
        for(i=1;i<=n1;i++)
            for(j=1;j<=n2;j++)
        {
            if(c1[i-1]==c2[j-1])
                    d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
      //  printf("%d\n",d[n1][n2]);


        
        s=n1;t=n2;
        k=d[s][t];
        
        while(i&&j)
        {
            if(c1[i-1]==c2[j-1]&&d[i][j]==d[i-1][j-1]+1)
            {
                c3[--k]=c1[i-1];
                --i;
                --j;
            }
            else if(c1[i-1]!=c2[j-1]&&d[i-1][j]>d[i][j-1])
                --i;
            else
                --j;
        }
//        printf("          ");
//        for(int i = 0;i <d[n1][n2];i++)
//        {
//        	
//        		printf("%d ",c3[i]);
//        		
//        }printf("\n");
        int qqq = c3[0];
        long long iq[1010];
		//printf("%d",c3[i]);
		iq[0] = c3[0];
        int ii = 1;
        
        for(int i = 1;i <d[n1][n2];i++)
        {
        	if(qqq<c3[i])
        	{
        	//	printf(" %d!",c3[i]);
        		qqq = c3[i];
        		iq[ii++] = qqq;
			}
        	else
        	 continue;
        }
        printf("%d\n%lld",ii,iq[0]);
        for(int i = 1;i < ii;i++)
        {
        	printf(" %lld",iq[i]);
		}
//        
//        for(int i = 0;i <n1;i++)
//        {
//        	
//        		printf(" %d",c1[i]);
//        		
//        }printf("\n");
//        for(int i = 0;i <n2;i++)
//        {
//        	
//        		printf(" %d",c2[i]);
//        		
//        }
//        
//        printf("\n");
//        
    
    return 0;
}
