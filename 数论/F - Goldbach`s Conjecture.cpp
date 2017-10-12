#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<deque>
using namespace std;
#define clr(x,y) memset(x,y,sizeof x)
const int maxn = 5e6 + 10;
bool is_[maxn];
int prime[maxn];
int len;
void Init()
{
    clr(is_,true);len = 0;prime[len ++] = 2;
    for(int i = 1; i < maxn; i ++)
    {
        int u = i * 2 + 1;
        if(is_[i])
        {
            prime[len ++] = u;
            for(int j = u * 2; j < maxn * 2; j += u)
                if(j % 2)is_[(j - 1)/2] = false;
        }
    }
}
int main()
{
    Init();
    int n;int Tcase;scanf("%d",&Tcase);
    for(int ii = 1; ii <= Tcase; ii ++)
    {
        scanf("%d",&n);
        int ans = 0;
        for(int i = 0; i < len && prime[i] * 2 <= n; i ++)
        {
            if( (n - prime[i])% 2 && is_[(n - prime[i] - 1) / 2])
            {
                ans ++;
            }
            if(i == 0 && n - prime[i] == 2)ans ++;
        }
        printf("Case %d: %d\n",ii,ans);
    }
    return 0;
}
