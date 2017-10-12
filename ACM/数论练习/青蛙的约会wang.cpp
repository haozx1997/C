#include <stdio.h>
#include <iostream>

#include <set>
#include<map>
#include <vector>
#include <math.h>
#include <string.h>
#include <queue>
#include <string>
#include <stdlib.h>
#define LL long long
#define _LL __int64
#define eps 1e-8
 
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10;
 
 
 
LL extend_gcd(LL a, LL b, LL &x, LL &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
 
    LL d = extend_gcd(b,a%b,x,y);
    LL t = x;
    x = y;
    y = t-a/b*y;
    return d;
}
 
int main()
{
    LL x,y,m,n,l;
    LL a,b,c,d;
    while(scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&l))
    {
        a = n-m;
        b = l;
        c = x-y;
 
        LL t,z;
        d = extend_gcd(a,b,t,z);
        printf("%d*%d+%d*%d=%d\n",a,t,b,z,d) ;
        if(c%d != 0)
        {
            printf("Impossible");
            continue;
        }
        t = t*(c/d);
        t = (t%b+b)%b;
        printf("%lld",t);
    }
    return 0;
}
