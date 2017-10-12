#include<stdio.h>
#include<string.h> 
#define ll long long

ll num(ll n)
{
	if(n == 1)
	{
		return (ll)0;
	}
    ll ans=1,i,k = 1;
    
    for(i=2;i*i<=n;i++)
    {
    	k = 0;
        if(n%i==0)
        {
            
            while(n%i==0)
            {
            	n/=i;
            	k++;
			}
            
        }
    //    printf("     %d\n",k);
        ans *= (k+1);
    }
    ans--;
    if(ans == 0)
    return 1;
    return ans;
}

int main()
{
	//freopen("1.in","r",stdin);
	int T;
	scanf("%d",&T);
	for(int TT = 1;TT <= T;TT++ )
	{
		ll aa;
		scanf("%I64d",&aa);
		printf("Case %d: %I64d\n",TT,num(aa));
	}
}
