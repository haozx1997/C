#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int x[100005],y[100005],p[100005],t[100005],s[100005];
int c=0,k=0;

int find1(int x)
{
    return p[x]==x?x:find1(p[x]);
}


int main()
{
    int i,max1,n,m,a1,s1;
    c=0,k=0;
    scanf("%d%d",&n,&m);
    
    for(i=1;i<=m;i++)
    {
    	scanf("%d%d",&x[i],&y[i]);
    }
    for(i=1;i<=n;i++)
    {
        p[i]=i;
    }
    for(i=1;i<=m;i++)
    {
        int a=find1(x[i]);
        int b=find1(y[i]);
        if(a!=b)
        p[a]=b;
    }
    for(i=1;i<=n;i++)
    {
    	printf("!%d %d\n",i,find1(i));
    }
    return 0;

}
