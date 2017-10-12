#include<bits/stdc++.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	char s[500];
	int n;
	while(T--)
	{
		memset(s,0,sizeof(s));
		scanf("%d",&n);
		scanf("%s",s);
		
	//	printf("%s\n",s);
		int ans = 0;
//		for(int i = 0;i < n;i++)
//		{
//			printf("%d %d %c\n",i,s[i],s[i]);
//		}
	//	printf("%s\n",s);
		for(int i = 0;i < n;i++)
		{
			int lr = 0;
			int ud = 0;
			for(int j = i;j < n;j++)
			{
			//	printf("%d %c\n",j,s[j]);
				if(s[j] == 'L')
				{
					lr++;
				}
				if(s[j] == 'R')
				{
					lr--;
				}
				if(s[j] == 'U')
				{
					ud++;
				}
				if(s[j] == 'D')
				{
					ud--;
				}
				if((lr == 0)&&(ud == 0))
				{
					ans++;
				//	printf("  %c %d\n",s[j],j);
				}
			}
		}
		printf("%d\n",ans);
	}




 return 0;
}


