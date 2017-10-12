#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

int u[10010],v[10010],w[10010],p[110],r[10010];
int nn,mm,kk;
int cmp(const int i, const int j)
{
    return w[i]<w[j];
}
int find(int x)
{
    return p[x]==x?x:(p[x]=find(p[x]));
}
int main()
{
	
	
	while(scanf("%d%d%d",&nn,&mm,&kk),nn)
		{

	for(int i=0;i<mm;i++)
	{
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
	}
	for(int i=0;i!=mm;i++)
        r[i]=i;//初始化边序号
	sort(r,r+mm,cmp);//给边排序
	while(kk--)
	{
		int st,end;
		scanf("%d%d",&st,&end);
		for(int i=0;i!=nn;i++)
        	p[i]=i;//初始化并查集

   
    for(int i=0;i!=mm;i++)
    {
        //找出当前边两个端点所在集合编号
        int e=r[i];
        int x=find(u[e]);
        int y=find(v[e]);
        //如果在不同集合，合并
        if(x!=y)
        {
            
            p[x]=y;
        }
        if(find(st)==find(end))
         {
         	printf("!!%d\n",w[e]);
            break;
		 }
    }

	}


	}

}
