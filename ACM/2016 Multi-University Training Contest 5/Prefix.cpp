#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<map>
#include<string>
#include<set>
#include<math.h>
 

using namespace std;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		string s[100005];
		for(int i = 0; i < n ;i++)
		{
			cin>>s[i];
			
		}
		
		int q;
		scanf("%d",&q);
		int z = 0;
		for(int i = 0; i < q ;i++)
		{
			int l,r,ll,rr;
			set<string> ss;
			ss.clear();
			scanf("%d%d",&l,&r);
			if(l == r)
			{
				z = sn[ll];
				printf("%d\n",z);
				continue;
			}
			ll = min(((z+l)%n),((z+r)%n));
			rr = max(((z+l)%n),((z+r)%n));
	
			string no;
			for(int ii = ll;ii <= rr;ii++)
			{
				for(int j = 0;j < s[ii].length() ;j++)
				{
					no.assign(s[ii],0,j+1);
					ss.insert(no);
				}
			}
				
			z = ss.size();
			printf("%d\n",z);
		}
		
	}
}
