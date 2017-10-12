#include<stdio.h>
#include<string.h>
#include<algorithm>


using namespace std;

struct node
{
	char s[100];
	int ca;
	bool operator < (const node& dd)const
	{
		return ca<dd.ca;
	}
}d[200];
int n,m;
int caa(char s[])
{
	int a,t,c,g;
	int ans = 0;
	a = t = c = g = 0;
	for(int i = m - 1;i>=0;i--)
	{
		switch(s[i])
		{
			case 'A':
				a++;
				break;
			case 'T':
				ans += a;
				ans += c;
				ans += g;
				break;
			case 'C':
				ans+=a;
				c++;
				break;
			case 'G':
				ans += a;
				ans += c;
				g++;
				break;
				
		}
	}
	return ans;
}

int main()
{
	
	while(~scanf("%d%d",&m,&n))
	{
		for(int i = 0;i < n;i++)
		{
			scanf("%s",d[i].s);
			d[i].ca = caa(d[i].s);
		}
		sort(d,d+n);
		for(int i = 0;i < n;i++)
		{
			printf("%s\n",d[i].s);
		}
	}




 return 0;
}


