#include<fstream>
#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

int n,m,u[10010],v[10010],w[10010],p[110],r[10010];
int cmp(const int i, const int j)
{
    return w[i]<w[j];
}
int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}
int main()
{
    int ans=0;
    cin>>n;
    m=n*n;
    int i,j,k=0;
    for(i=0;i!=n;i++)
        for(j=0;j!=n;j++)
        {
            cin>>w[k];
            u[k]=i;
            v[k]=j;
            k++;
        }
    for(i=0;i!=n;i++)
        p[i]=i;
    for(i=0;i!=m;i++)
        r[i]=i;
    sort(r,r+m,cmp);
    for(i=0;i!=m;i++)
    {
        int e=r[i];
        int x=find(u[e]);
        int y=find(v[e]);
        if(x!=y)
        {
            ans+=w[e];
            p[x]=y;
        }
    }
    cout<<ans<<endl;
    return 0;
}
