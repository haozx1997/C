#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
using namespace std;

char a[1010];
int c[2010][2000];
int main()
{
    int T,n;
    memset(c,0,sizeof(c));
    c[0][0]=1;
    for(int i=1; i<=510; i++)
    {
        c[i][0]=1;
        for(int j=1; j<=510; j++)
        {
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%1000000007;
        }
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",a);
        int len=strlen(a);
        int vis[30];
        memset(vis,0,sizeof(vis));
        for(int i=0; i<len; i++)
        {
            vis[a[i]-'a']++;
        }
        int f=0;
        for(int i=0; i<26; i++)
        {
            if(vis[i]%2!=0)
            {
                f++;
            }
        }
        if(len%2==0)
        {
            if(f>0)
            {
                printf("0\n");
            }
            else
            {
                len/=2;
                long long sum=1;
                for(int i=0; i<26; i++)
                {
                    if(vis[i]!=0)
                    {
                        vis[i]/=2;
                        sum=(c[len][vis[i]]%1000000007)*(sum%1000000007);
                        sum%=1000000007;
                        len-=vis[i];
                    }
                }
                printf("%I64d\n",sum);
            }
        }
        else
        {
            if(f>1)
            {
                printf("0\n");
            }
            else if(f==1)
            {
                len/=2;
                long long sum=1;
                for(int i=0; i<26; i++)
                {
                    if(vis[i]!=0)
                    {
                        vis[i]/=2;
                        sum=(c[len][vis[i]]%1000000007)*(sum%1000000007);
                        sum%=1000000007;
                        len-=vis[i];
//                        printf("%d\n",len);
                    }
                }
                printf("%I64d\n",sum);
            }
        }
    }
    return 0;
}
/*
123
qweqweqweqweqweqweqweqweqweqwe
kljhfasdfjklhasdkljfhaslkdjfh
aaaaaallllllqqqqqqpppppp


*/
