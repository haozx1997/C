#include<bits/stdc++.h>

using namespace std;

struct node
{
	int x,y;
}a[100100];

char s[100100];
int main()
{
	int n;
	int T;
	scanf("%d",&T);
	getchar();
	while(T--)
	{
		
		memset(s,0,sizeof(s));
		gets(s);
		memset(a,0,sizeof(a));
		n = 0;
		int len = strlen(s);
		for(int i = 0;i < len ;i++)
		{
				
			if(s[i] == ')')
			{
				s[i] = '\0';
			}
			
		}
		for(int i = 0;i < len ;i++)
		{
		//	printf("%d %c\n",i,s[i]);
			if(s[i] == '(')
			{
		//		printf("%d len %d %c\n",i,strlen(&s[i+1]),s[i]);
				sscanf(&s[i+1],"%d,%d",&a[n].x,&a[n].y);
				n++;
				i += (strlen(&s[i+1])-1);
			}
			
		}
//		for(int i = 0;i < n ;i++)
//		{
//				
//			printf("%d %d\n",a[i].x,a[i].y);
//			
//		}
//		
		double ans = 1000000000.0;
		double now = 0.0;
		for(int i = 0;i < n;i++)
		{
			for(int j = i+1;j<n;j++)
			{
				now = sqrt((double)((double)(a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)));
				ans = min(now,ans);
			}
		}
		printf("%.4f\n",ans);
		
	}




 return 0;
}


