#include<stdio.h>
#include<algorithm>

#define ll long long
using namespace std;

int a1[200];
int a2[200];

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int n1 = n/2;
		int s1 = 0;
		int s2 = 0;
		int n2 = n - n1;
		for(int i = 0; i < n1;i++)
		{
			scanf("%d",&a1[i]);
			s1 += a1[i];
		}
		for(int i = 0; i < n2;i++)
		{
			scanf("%d",&a2[i]);
			s2 += a2[i];
		}
		if(n == 1)
		{
			printf("%d %d\n",a2[0],a2[0]);
			continue;
		}
		int sha = abs(s1-s2);
		int sh1 = s1;
		int sh2 = s2;
		
		for(int i = 0; i < 1000086;i++)
		{
			int z = rand()%n1;
			int x = rand()%n2;
			s1 = s1 - a1[z] + a2[x];
			s2 = s2 + a1[z] - a2[x];
			swap(a1[z],a2[x]);
			if(abs(s1-s2)<sha)
			{
				sha = abs(s1-s2);
				sh1 = s1;
				sh2 = s2;
			}
			
		}
		printf("%d %d\n",min(sh1,sh2),max(sh1,sh2));
	}




 return 0;
}


