#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>

using namespace std;

char c1[1005],c2[1005],c3[1005];
int d[1005][1005];
int main()
{
    while(scanf("%s%s",c1,c2)!=EOF)
    {
        int i,j,s,t,k;
        memset(d,0,sizeof(d));
        for(i=0;i<=strlen(c1);i++)
            d[i][0]=0;
        for(j=0;j<=strlen(c2);j++)
            d[0][j]=0;
        for(i=1;i<=strlen(c1);i++)
            for(j=1;j<=strlen(c2);j++)
        {
            if(c1[i-1]==c2[j-1])
                    d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
        printf("%d\n",d[strlen(c1)][strlen(c2)]);


        
        s=strlen(c1);t=strlen(c2);
        k=d[s][t];
        c3[k]={'\0'};
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
        printf("%s\n",c3);
    }
    return 0;
}
