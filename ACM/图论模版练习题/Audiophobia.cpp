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
        r[i]=i;//��ʼ�������
	sort(r,r+mm,cmp);//��������
	while(kk--)
	{
		int st,end;
		scanf("%d%d",&st,&end);
		for(int i=0;i!=nn;i++)
        	p[i]=i;//��ʼ�����鼯

   
    for(int i=0;i!=mm;i++)
    {
        //�ҳ���ǰ�������˵����ڼ��ϱ��
        int e=r[i];
        int x=find(u[e]);
        int y=find(v[e]);
        //����ڲ�ͬ���ϣ��ϲ�
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
