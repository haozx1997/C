#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int b,e;
		int ans = 0;
		scanf("%d%d",&b,&e);
		for(int i = b;i <= e;i++)
		{
			int two = i%100;
			int three = i%1000;
			double root;
			
			root = sqrt(two);
			if(root == (int)root &&(int)root<=12&&(int)root>0)
			{
			//	printf("root %d\n",(int)root);
				ans++;
			 } 
			// printf("nm %d %d %d\n",two!=three,two,three);
			if(two!=three)
			{
				root = sqrt(three);
				if(root == (int)root &&(int)root<=12&&(int)root>0)
				{
					//printf("root %d\n",(int)root);
					ans++;
				 } 
			}
		}
		printf("%d\n",ans);
	}
}
