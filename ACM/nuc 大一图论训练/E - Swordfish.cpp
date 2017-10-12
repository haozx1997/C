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
	    //��i���ߵ������˵���ź�Ȩֵ�ֱ𱣴���u[i],v[i]��w[i]��
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
	        p[i]=i;//��ʼ�����鼯
	    for(i=0;i!=m;i++)
	        r[i]=i;//��ʼ�������
	    sort(r,r+m,cmp);//��������
	    for(i=0;i!=m;i++)
	    {
	        //�ҳ���ǰ�������˵����ڼ��ϱ��
	        int e=r[i];
	        int x=find(u[e]);
	        int y=find(v[e]);
	        //����ڲ�ͬ���ϣ��ϲ�
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
