#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define ll long long
map<ll,ll>mp;
int main()
{
    long long m,i,a[100009];
    scanf("%I64d",&m);
    for(i=0;i<m;i++)
	{
    	scanf("%I64d",&a[i]);
        
        mp[a[i]]++;
	}
    sort(a,a+m);
    ll  sum = 0;
    if(a[0]==a[1]&&a[1]==a[2]){
        ll  num = mp[a[0]];
        sum = (num*(num-1)*(num-2))/6;
    }
    if(a[1]!=a[2]){
        ll num = mp[a[2]];
       sum = num;
    }
    if(a[0]!=a[1]&&a[1]==a[2]){
        ll num = mp[a[2]];
       // num = 99999;
        sum = (num*(num-1))/2;
    }

    printf("%I64d\n",sum);
}
