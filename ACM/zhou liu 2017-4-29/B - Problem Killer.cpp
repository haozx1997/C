#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long n;
		long long a[100100];
		scanf("%lld",&n);
		for(int i = 0 ; i < n;i++)
		{
			scanf("%lld",&a[i]);
		}
		long long ad = a[1] - a[0];
		long long adn = 2;
		long long admax = 0;
		
		double ap = (double)a[1]/a[0];
		long long apn = 2;
		long long apmax = 0;
		
		for(long long i = 1;i < n-1;i++)
		{
			
			if(ad == (a[i+1]-a[i]))
			{
				adn++;
				if(admax<adn)
				{
					admax = adn;
				}
			}
			else
			{
				ad = (a[i+1]-a[i]);
				adn = 2;
			}
			
		}
		for(long long i = 1;i < n-1;i++)
		{
			
			if(ap == ((double)a[i+1]/a[i]))
			{
				apn++;
				if(apmax<apn)
				{
					apmax = apn;
				}
			}
			else
			{
				ap = ((double)a[i+1]/a[i]);
				apn = 2;
			}
			
		}
		
		printf("%lld\n",max(apmax,admax)); 
		
	}




 return 0;
}


