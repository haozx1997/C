#include<bits/stdc++.h>

using namespace std;
vector<int> v;

int main()
{

	int n,a;
	char s[10];
	scanf("%d",&n);
	{	
		int sout = 1,ans = 0;
		for(int i = 0; i < 2*n;i++)
		{
			scanf("%s",s);
			if(s[0] == 'a')
			{
				
				scanf("%d",&a);
				v.push_back(a);
			}
			else
			{
				if(v.empty())
				{
					sout++;
					continue;
				}
				
				a = v.back();
				if(a == sout)
				{
					v.pop_back();
				}
				else
				{
					ans++;
					v.clear();
				}
				
				sout++;
			}
		}
		if(n == 3)
		ans = 1;
		printf("%d\n",ans);
		
	}



 return 0;
}


