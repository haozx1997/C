#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		int a,b;int F = 0;
		scanf("%d%d",&a,&b);
		if(a != b)
		{
				F = 1;
		}
		int aa,bb;
		
		for(int i = 1;i < n;i++)
		{
			scanf("%d%d",&aa,&bb);
			if(aa != bb)
			{
				F = 1;
			}
			if(bb > b&&F != 1)
			{
				F = 2;
			}
			a = aa;
			b = bb;
		}
		switch(F)
		{
			case 2:
				 printf("unrated\n");
				 break;
			case 1:
				 printf("rated\n");
				 break;
			case 0:
				 printf("maybe\n");
				 break;
				 
		}
	}




 return 0;
}


