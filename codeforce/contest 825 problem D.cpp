#include<bits/stdc++.h>
using namespace std;
map<char,int>ss,tt;
int cnt;
main()
{
	int i;string s,t;
	while(cin>>s>>t)
	{
		ss.clear();
		tt.clear();
		
		for(i=0;i<s.size();++i)
		{
			ss[s[i]]++;
		}
		
		for(i=0;i<t.size();++i)
		{
			tt[t[i]]++;
		}
		char cur='a';
		for(i=0;i<s.size();++i)
		{
			while(s[i]=='?')
			{
				if(cur>'z')cur='a';
				for(char c=cur;c<='z';++c)
				{
					if(ss[c]<tt[c])
					{
						s[i]=c,ss[c]++;
						if(ss[c]==tt[c])ss[c]-=tt[c],cur++;
						break;
					}
					else ss[c]-=tt[c],cur++;
				}
			}
		}
		cout<<s<<endl;
	}
	
}
/*
?aa?
ab

??b?
za

abcd
abacaba

*/

