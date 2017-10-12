#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int x[100005],y[100005],p[100005],t[100005],s[100005];
int c=0,k=0;
int cmp(const void *a,const void *b)
{
    return *(int*)a-*(int*)b;
}

int find1(int x)
{
    return p[x]==x?x:find1(p[x]);
}


int main()
{
    int i,max1,n,m,a1,s1;
    cin>>n>>m;
    
    for(i=1;i<=m;i++)
    x[i]=y[i]=i;
    for(i=1;i<=m;i++)
    cin>>x[i]>>y[i];
    for(i=1;i<=n;i++)
    {
        p[i]=i;
        t[i]=0;
    }
    for(i=1;i<=m;i++)
    {
        int a=find1(x[i]);
        int b=find1(y[i]);
        if(a!=b)
        p[a]=b;
    }
    for(i=1;i<=n;i++)
        t[find1(i)]++;
    max1=t[1];
    for(i=2;i<=n;i++)
        if(t[i]>max1)
            {
                     max1=t[i];
                     s1=i;
            }
    cout<<max1<<endl;
    for(i=1;i<=n;i++)
    {
        if(find1(i)==s1)
            s[k++]=i;
    }

	for(i=1;i<=n;i++)
    {
        printf("%d %d\n",i,find1(i));
    }
    qsort(&s,max1,sizeof(s[0]),cmp);
    
    for(i=0;i<max1;i++)
    printf(c++?" %d":"%d",s[i]);

    return 0;

}
