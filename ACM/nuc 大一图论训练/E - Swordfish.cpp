//4
//0 4 9 21
//4 0 8 17
//9 8 0 16
//21 17 16 0
#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<math.h>
using namespace std;

int n,m,u[10010],v[10010],p[110],r[10010];
double w[10010];
double xx[10010],yy[10010];
int cmp(const int i, const int j)
{
    return w[i]<w[j];
}
double dis(double aa,double bb,double cc,double dd)
{
	double disx=fabs(aa-cc);
	double disy=fabs(bb-dd);

	return sqrt(disx*disx+disy*disy);
}
int find(int x)
{
    return p[x]==x?x:p[x]=find(p[x]);
}
int main()
{
	
	while(scanf("%d",&n),n)
	{
		
		double ans=0;
	    
	    m=n*n;
	    int i,j,k=0;
	    //第i条边的两个端点序号和权值分别保存在u[i],v[i]和w[i]中
	//    for(i=0;i!=n;i++)
	//        for(j=0;j!=n;j++)
	//        {
	//            cin>>w[k];
	//            u[k]=i;
	//            v[k]=j;
	//            k++;
	//        }
		for(int ii=0;ii<n;ii++)
			{
				scanf("%lf%lf",&xx[ii],&yy[ii]);
			}
		for(int ii=0;ii<n-1;ii++)
		{
			for(int jj=ii+1;jj<n;jj++)
			{
	            w[k]=dis(xx[ii],yy[ii],xx[jj],yy[jj]);
	            u[k]=ii;
	            v[k]=jj;
	            k++;
							
				
			}
		}
	
		
	    for(i=0;i!=n;i++)
	        p[i]=i;//初始化并查集
	    for(i=0;i!=m;i++)
	        r[i]=i;//初始化边序号
	    sort(r,r+m,cmp);//给边排序
	    for(i=0;i!=m;i++)
	    {
	        //找出当前边两个端点所在集合编号
	        int e=r[i];
	        int x=find(u[e]);
	        int y=find(v[e]);
	        //如果在不同集合，合并
	        if(x!=y)
	        {
	            ans+=w[e];
	            p[x]=y;
	        }
	    }
	    printf("%.2f\n",ans);
	}

    return 0;
}
