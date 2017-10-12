#include<bits/stdc++.h>

using namespace std;


map<pair<int,int>,bool>have;


int xx[1000000];
int yx[1000000];


int main()
{

	int n = 1000;
//	puts("cnm");
//	while(~scanf("%d",&n))
	{
		have.clear();
		for(int i = 1;i <=n;i++)
		{
			
			xx[i] = i,yx[i] = i;
			have[make_pair(xx[i],yx[i])] = 1;
			
		}
		int ans = 0;
		
		for(int i = 1;i<=n;i++)
		{
			for(int j = i+1;j<=n;j++)
			{
				
				int x1 = xx[i];
				int y1 = yx[i];
				int x2 = xx[j];
				int y2 = yx[j];
				int xd = x2-x1;
				int yd = y2-y1;
				
//				printf("	%d %d %d %d\n",x1,y1,x2,y2);
//				printf("%d   ",have[make_pair(x1-yd,y1+xd)]);
//				printf("%d \n",have[make_pair(x2-yd,y2+xd)]);
//				printf("%d   ",have[make_pair(x1+yd,y1-xd)]);
//				printf("%d \n",have[make_pair(x2+yd,y2-xd)]);
//				
//				
				if(have.count(make_pair(x1-yd,y1+xd)))
				if(have.count(make_pair(x2-yd,y2+xd)))
				ans++;
				
				if(have.count(make_pair(x1+yd,y1-xd)))
				if(have.count(make_pair(x2+yd,y2-xd)))
				ans++;
				
//				if((have[make_pair(x1-yd,y1+xd)] == 1)&&(have[make_pair(x2-yd,y2+xd)] == 1))
//				{
//					ans++;
//				}
//				if((have[make_pair(x1+yd,y1-xd)] == 1 )&&have[make_pair(x2+yd,y2-xd)])
//				{
//					ans++;
//				}
//				
				
			}
		}
		
		printf("%d\n",ans/4);
		
	 } 
	




 return 0;
}

/*
6
0 0
0 1
1 0
1 1
2 0
2 1

6
0 0
0 1
2 0
2 1
1 0
1 1

6

1 0
1 1
2 0
2 1
0 0
0 1


*/





