#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	int aa[1000],a;
	while(~scanf("%d",&n))
	{
		memset(aa,0,sizeof(aa));
		for(int i = 0 ; i < n;i++)
		{
			scanf("%d",&a);
			aa[a] = 1;
		}
		int bo = 0;
		int i = 0;
		for(i = 1;i <= 90;i++)
		{
			if(aa[i]!=1)
			{
				bo++;
			}
			else
			{
				bo = 0;
			}
			if(bo>=15)
			{
				break;
			}
		}
		printf("%d\n",min(90,i));
	}




 return 0;
}


