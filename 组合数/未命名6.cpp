#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
#include<string>
#define nl n<<1
#define nr (n<<1)|1
using namespace std;
typedef long long ll;

const ll mod=1e9+7;

long long asd[105][105][10][2][2];
int qwe[105];
char str[105];
ll rec(int i,int pre,int up,int down,int flag,int q,int len)
{
    if(i<0)
        return 1;
    if(asd[i][len][pre][up][down]!=-1&&!flag&&!q)
        return asd[i][len][pre][up][down];
    ll res=0;
    int o=qwe[i];
    for(int j=0; j<10; j++)
    {
        if(j>o&&flag)
            break;
        if(q)
            res+=rec(i-1,j,0,0,j<o?0:flag,q&&j==0,len-(q&&j==0)),res%=mod;
        else if(j==pre)
        {
            res+=rec(i-1,j,up,down,j<o?0:flag,q&&j==0,len),res%=mod;
        }
        else if(j>pre)
        {
            res+=rec(i-1,j,1,down,j<o?0:flag,q&&j==0,len),res%=mod;
        }
        else if(j<pre)
        {
            if(up)
                continue;
            res+=rec(i-1,j,up,1,j<o?0:flag,q&&j==0,len),res%=mod;
        }
    }
    if(!flag&&!q)
        asd[i][len][pre][up][down]=res;
    return res;
}
long long cal()
{
    int len=strlen(str);
    for(int i=0; i<len; i++)
    {
        qwe[i]=str[len-1-i]-'0';
        //printf("%d\n",qwe[i]);
    }
    return rec(len-1,0,0,0,1,1,len);
}
int main()
{
    memset(asd,-1,sizeof(asd));
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        printf("%I64d\n",(cal()-1+mod)%mod);
    }
    return 0;
}

