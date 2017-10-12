#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<set>
#define ll long long
using namespace std;

int is2357(int num)
{
		while(!(num%2))
		{
			num /= 2;
		}
		while(!(num%3))
		{
			num /= 3;
		}
		while(!(num%5))
		{
			num /= 5;
		}
		while(!(num%7))
		{
			num /= 7;
		}	
		if(num == 1)
		return 1;
		return 0;
}

ll pow(ll x,ll n)
{
	if(x == 0) return 0;
    if(n==0) return 1;
    else
    {
        while((n&1)==0)
        {
            n>>=1;
            x*=x;
        }
    }
    ll result=x;
    n>>=1;
    while(n!=0)
    {
        x*=x;
    if((n&1)!=0)
        result*=x;
    n>>=1;
    }
    return result;
}
 
long long a[100000];




int main()
{
	set<long long> s;
	int k = 0;
	long long now;
	for(int i1 = 0;i1<33;i1++)
	{
			for(int i2 = 0;i2<20;i2++)
	{
			for(int i3 = 0;i3<15;i3++)
	{
			for(int i4 = 0;i4<13;i4++)
	{
		now = pow((ll)2,(ll)i1)*pow((ll)3,(ll)i2)*pow((ll)5,(ll)i3)*pow((ll)7,(ll)i4);
		
		if(now<=(ll)1000000000&&now>=0)
		 {
		 //	printf("%lld\n",now);
		 	s.insert(now);
		 }
	}
	}
	}
	}
	
	    set<long long>::iterator it; //??????? 

	for(it=s.begin();it!=s.end();it++) 
    a[k++] = *it; 
    int T;
    scanf("%d",&T);
    while(T--)
    {
    	ll ff;
    	scanf("%I64d",&ff);
    	int l = 0,r = k-1;
    	while(1)
    	{
    		if((r-l)==1) 
    		{
    			printf("%I64d\n",a[r]);
    			break;
			}
			int m = (l+r)/2;
			if(ff>a[m])
			{
				l = m;
			}
			else
			{
				r = m;
			}
		}
	}
    

}
