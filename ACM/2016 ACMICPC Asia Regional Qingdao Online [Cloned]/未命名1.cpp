/*Sherlock and Watson and Adler*/  
#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include<stdio.h>  
#include<string.h>  
#include<stdlib.h>  
#include<queue>  
#include<stack>  
#include<math.h>  
#include<vector>  
#include<map>  
#include<set>  
#include<bitset>  
#include<cmath>  
#include<complex>  
#include<string>  
#include<algorithm>  
#include<iostream>  
#define eps 1e-9  
#define LL long long  
#define PI acos(-1.0)  
#define bitnum(a) __builtin_popcount(a)  
using namespace std;  
const int N = 100005;  
const int M = 100005;  
const int inf = 1000000007;  
const int mod = 1000000007;  
int main()  
{  
    __int64 L,R;  
    while(~scanf("%I64d%I64d",&L,&R))  
    {  
        if(!L)  
            L++;  
        if(!R)  
            R++;  
        if(R-L>=2)  
            printf("%I64d\n",(R-L)/2+1);  
        else if(L==R)  
        {  
            if(L==1)  
                puts("0");  
            else if(L==2)  
                puts("1");  
            else  
                puts("2");  
        }  
        else  
        {  
            if(L==1&&R==2)  
                puts("1");  
            else  
                puts("2");  
        }  
    }  
    return 0;  
}  
