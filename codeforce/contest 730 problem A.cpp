#include<bits/stdc++.h>

using namespace std;

struct node
{
	int a,i;
	bool operator < (const node& xx)const
	{
		return a>xx.a;
	}
};

multiset<node>S;
multiset<int>::reverse_iterator rit;
multiset<int>::iterator it;
int out[2000][200];
int outn;
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		
		memset(out,0,sizeof(out));
		outn = 0;
		for(int i =0 ;i < n;i++)
		{
			int a;
			scanf("%d",&a);
			S.insert((node){ a,i });
		}
		while(((*S.begin()).a )!=((*S.rbegin()).a ))
		{
			int cn = 0;
		}
			
	}
	



 return 0;
}


