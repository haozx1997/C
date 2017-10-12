#include<stdio.h>
#include<string.h> 
#define ll long long

ll eul(ll n)
{
    ll ret = n,i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ret = ret - ret/i;
            n/=i;	
            while(n%i==0)
            n/=i;	
        }
    }
    if(n>1)
    ret = ret - ret/n;
    return ret;
}

ll phi[101010];
ll eul_list(ll n)
{  
	phi[1] = 1; 
    for(int i=2; i<=n; ++i)  
        phi[i] = 0;  
     
    for(int i=2; i<=n; ++i) 
		if((phi[i] == 0))  
	        for(int j=i; j<=n; j+=i)  
	        {  
	            if(phi[j] == 0) 
					phi[j] = j;  
	            phi[j] = phi[j]/i * (i-1);  
	        }  
}

int main()
{
	ll n;
	eul_list(1000);
	while(~scanf("%I64d",&n))
	{
		
		printf("%I64d\n",eul(n));
		printf("%I64d\n",phi[n]);
		
	}
}
