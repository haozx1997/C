#include<bits/stdc++.h>

using namespace std;
int a;
int main()
{
	int n,q;
	list<int> l;
	list<int> ::iterator it;
	while(~scanf("%d%d",&n,&q))
	{
		l.clear();
		it = l.begin();
		for(int i =1;i<= n;i++)
		{
			scanf("%d",&a);
			l.insert(it++,a);
		}
		while(q--,0)
		{
//			for(int i = 0;i<=n;i++)
//			{
//			//	printf("%d ",a[i]);
//			}
		//	printf("\n");
			int c,k,x;
			scanf("%d",&c);
			if(c == 1)
			{
				scanf("%d%d",&k,&x);
				
			}
			if(c == 2)
			{
				scanf("%d",&k);
				
			}
			if(c == 3)
			{
				scanf("%d",&k);
				
			}
			
		}
	}
}
