#include<bits/stdc++.h>

using namespace std;
int w,t,f;
int id(char s[])
{
	int h = ELFhash(s);
	if(!hash[h])
	{
		hash[h] = ++w;
	}
	return hash[h];
}

int main()
{

	int n;
	while(~scanf("%d",&n))
	{
		
		int w = 0;
		char ts[100],ws[100];
		for(int i = 0;i < n;i++)
		{
			scanf("%s%s",ts,fs);
			t = id(ts);
			f = id(fs);
			printf("%d %d\n",t,f);
		}
	}



 return 0;
}


