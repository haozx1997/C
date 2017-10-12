#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <string>  
#include <algorithm>  
  
using namespace std;  
  
#define LL long long  
const int INF = 0x3f3f3f3f;  
#define MAXN 500  
  
char s[2000006];  
char ch[2000005];  
int main()  
{  
    int n,m,x;  
  
    int tot=0;  
    scanf("%d",&n);  
    for(int i=0; i<n; i++)  
    {  
        scanf("%s%d",&ch,&m);  
        int k=strlen(ch);  
        int t=-INF;  
        for(int j=0; j<m; j++)  
        {  
            scanf("%d",&x);  
            x--;  
            tot=max(x+k,tot);  
            for(int l=max(x,t); l<x+k; l++)  
                s[l]=ch[l-x];  
            t=x+k;  
        }  
    }  
    for(int i=0; i<tot; i++)  
        if(s[i]=='\0')  
            printf("a");  
        else  
            printf("%c",s[i]);  
    printf("\n");  
  
    return 0;  
} 
