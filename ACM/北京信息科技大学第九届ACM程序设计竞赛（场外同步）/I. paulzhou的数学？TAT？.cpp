#include<bits/stdc++.h>

using namespace std;

int main()
{

	char s[500];
	int T;
	scanf("%d",&T);
	while(~scanf("%s",s))
	{
		int len = strlen(s);
		if(len>12)
		{
			printf("TAT\n");
			continue;
		}
		long long a;
		sscanf(s,"%lld",&a);
		long long aa = a;
		int F = -1;
		for(int i = 0;i <= 5;i++)
		{	
	//		printf("%d %lld\n",i,aa);
			if(aa == (long long )1)
			{
				F = i;
				break;
			}
			aa = (long long)sqrt(aa);
		}
		if(F != -1)
		{
			printf("%d\n",F);
		}
		else
		{
			printf("TAT\n");
		}
	}



 return 0;
}


