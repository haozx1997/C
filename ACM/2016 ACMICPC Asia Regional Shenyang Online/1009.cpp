#include<stdio.h>
#include<algorithm>
#include    <string.h>  
#include    <stdlib.h>  
#include    <math.h>  
#define ll long long
using namespace std;
struct note
{
	ll k;
	ll v;
}a[400];
int rp[400];
ll pre = 1;
int isrp(ll a, ll b){
//	printf("%I64d %I64d  ",a,b);
pre = 1;
	if(a <=0 || b<=0 || a==b){   
		return 0;
	}else if(a==1 || b==1){  // �����������У�ֻ������һ����ֵΪ1������������Ϊ������
		return 1;
	}else{
		//  ������������������Լ��
		while(1){
			ll t = a%b;
			if(t == 0){
				break;
			}else{
				a = b;
				b = t;
			}
		}
		pre = b;
//		printf("pre %d\n",pre);
		if( b > 1){  // ������Լ������1����ʾ����������������
			return 0;
		}else{         // ������Լ������1,��ʾ��������������
			return 1;
		}
	}
}
ll sttl[300];//something to lose
int sttln;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		  
         
        pre = 1;  
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n;i++)
		{
			scanf("%I64d",&a[i].k);
		}
		for(int i = 0; i < n;i++)
		{
			scanf("%I64d",&a[i].v);
		}
		memset(rp,0,sizeof(rp));
		
		rp[0] = isrp(a[0].k,a[1].k);
		for(int i = 1; i < n-1;i++)
		{
			
//			if(pre!=1)
//			{
//				if(!(a[i+1].k%pre))
//			{
//				rp[i] = 0;
//			}
//			}
//			else
			{
				rp[i] = isrp(a[i].k,a[i+1].k);
			}
		}
	//	printf("��ʱ %lf\nrp",end);
//	printf("rp :");
//		for(int i = 0;i < n-1;i++)
//		{
//			printf("%d ",rp[i]);
//		}
//		printf("\n");
		int be = 0;
		int en = 0;
		ll ans = 0;
		for(int i = 0;i < n-1;i++)//[be en) ����ҿ� 
		{
			if(rp[i] == 0&&i!=(n-2))
			{
				en = i+1;
			}
			else
			{
				 if(rp[i] == 0&&i==(n-2))
				 {
				 	en += 1;
				 }
				//printf("%d %d\n",be,en);
				int ca = en - be;
				if(ca == 0)
				{
					en = be =i+1;
					continue;
				}
				if((ca%2)&&ca!=0)//�ܼӵ���Ϊż�� <-���Զ���Ϊ������%2�� 
				{
					for(int ii = be;ii<=en;ii++)
					{
						ans += a[ii].v;
					//	printf("%I64d ",a[ii].v);
					}
				}
				else 
				{
					memset(sttl,0,sizeof(sttl));
					sttln = 0;
					for(int ii = be;ii<=en;ii++)
					{
						ans += a[ii].v;
						if(!(ii%2))
						{
							sttl[sttln++] = a[ii].v;
							
						}
					}
					sort(sttl,sttl+sttln);
					ans -= sttl[0];
	//				for(int iiii = 0; iiii<sttln;iiii++)
	//				{
	//					printf("%I64d ",sttl[iiii]);
	//				}
	//				printf("100 %I64d\n",sttl[0]);
				}
				be = i;
			}
		}
		printf("%I64d\n",ans);
	}
 } 
