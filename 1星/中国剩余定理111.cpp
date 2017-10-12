#include <iostream>  
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
using namespace std;  
  
__int64 x,y;  
  
__int64 extended_euclid(int s,int t)   //??????  
{  
    __int64 i,temp;  
    if(t==0)  
    {  
        x=1;  
        y=0;  
        return s;  
    }  
    else   
    {  
        i=extended_euclid(t,s%t);  
        temp=x;  
        x=y;  
        y=temp-(s/t*y);  
        return i;  
    }  
}  
  
int main()  
{  
    __int64 a1,a2,b1,b2,t,c,n,m,i,j;  
    while(scanf("%I64d",&t)!=EOF)  
    {  
        scanf("%I64d%I64d",&a1,&b1);  
        int ok=0;  
        for(i=0;i<t-1;i++)  
        {  
            scanf("%I64d%I64d",&a2,&b2);  
            if(ok) continue;  
            int e=extended_euclid(a1,a2);  
            c=b2-b1;  
            if(c%e)  
            {  
                ok=1;  
                continue;  
            }  
            int q=a2/e;  
            x=(x*c/e%q+q)%q;      //????????  
            b1=a1*x+b1;           // b=x;  
            a1=a1*a2/e;           // a?a1?a2???????  
        }  
        
        if(ok) printf("-1\n");  
        else printf("%lld\n",b1);  
    }  
    return 0;  
}  
