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

int isrp(ll a, ll b){

	if(a <=0 || b<=0 || a==b){
		return 0;
	}else if(a==1 || b==1){
		return 1;
	}else{
		while(1){
			ll t = a%b;
			if(t == 0){
				break;
			}else{
				a = b;
				b = t;
			}
		}

		if( b > 1){
			return 0;
		}else{
			return 1;
		}
	}
}
ll sttl[300];
int sttln;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{


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

			{
				rp[i] = isrp(a[i].k,a[i+1].k);
			}
		}

		int be = 0;
		int en = 0;
		ll ans = 0;
		for(int i = 0;i < n-1;i++)
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
				int ca = en - be;
				if(ca == 0)
				{
					en = be =i+1;
					continue;
				}
				if((ca%2)&&ca!=0)
				{
					for(int ii = be;ii<=en;ii++)
					{
						ans += a[ii].v;
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
				}
				be = i;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
 }

