
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int cccc[10000];

int n  =0 ;
	int m  =0;map<int,int> mm;
int solve()
{
	string s ;
	while(cin>>s)
	{
	
		if(s=="END")
		{
			break;
		}
		long long now;
		n++;	
		int len = s.length();
		s[s.length()-1] = 0;
		char sss[100];
		for(int i = 0; i < s.length();i++)
		{
			sss[i] = s[i];
		}
		sss[len-1] = 0;
		sscanf(sss,"%X",&now);
		int cai = now%64;
		
		if(mm[cai] != now)
		{
			printf("Miss\n");
			mm[cai] = now;
		}
		else
		{
			printf("Hit\n"); 
			m++;	
		}
		
		
	}
	
	printf("Hit ratio = %.2f",(double)m*100/n);
	puts("%");
}


int main()
{
	solve();
	

/*


AAAA000
00010B2
00010BA
END

AAAA000
00010B2
END


*/

 return 0;
}


