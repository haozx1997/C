#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;

const int mmax=30000;//最底层30000个结点的满二叉树
int data[mmax+5];
int tarr[mmax*4+5];

void build(int p,int l,int r)//p表示当前位置
{
    if(l==r)
    {
        tarr[p]=data[l];
        return ;
    }
    int m=(l+r)>>1;
    int L=p<<1;
    int R=p<<1|1;
    build(L,l,m);
    build(R,m+1,r);
    tarr[p]=max(tarr[L],tarr[R]);
}

int Query(int a,int b,int p,int l,int r)
{
    if(a<=l&&r<=b)
        return tarr[p];

    int m=(l+r)>>1;
    int L=-1;
    int R=-1;
    if(a<=m) L=Query(a,b,p<<1,l,m);
    if(m<b)  R=Query(a,b,p<<1|1,m+1,r);

    if(L==-1) return R;
    if(R==-1) return L;
    return max(R,L);
}
void Update(int idy,int value,int p,int l,int r)
{
    if(l==r&&l==idy)
    {
        tarr[p]=value;
        return ;
    }

    int m=(l+r)>>1;
    if(idy<=m) Update(idy,value,p<<1,l,m);
    if(m<idy)  Update(idy,value,p<<1|1,m+1,r);

    tarr[p]=max(tarr[p<<1],tarr[p<<1|1]);//返回的时候看左边大还是右边大
}

int main()
{
    int N,M;
    while(~scanf("%d%d",&N,&M))
    {
        for(int i=1;i<=N;i++)
            scanf("%d",&data[i]);
        build(1,1,N);

        char ch;
        int a,b;

        while(M--)
        {

            scanf(" %c%d%d",&ch,&a,&b);
            if(ch=='U')
                Update(a,b,1,1,N);
            else if(ch=='Q')
            {
                if(a>b) swap(a,b);
                printf("%d\n",Query(a,b,1,1,N));
            }
        }
    }
    return 0;
}
