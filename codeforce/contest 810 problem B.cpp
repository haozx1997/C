#include<bits/stdc++.h>

using namespace std;

long long min(long long a,long long b)
{
	if(a>b)
	 return b;
	return a; 
}


struct node
{
	long long o,d;
	bool operator < (const node& dd)const
	{
		return (dd.d-dd.o)>(d-o);
	}
}no[100100];

int main()
{

	int n,f;

	while(~scanf("%d%d",&n,&f))
	{
		long long sum = 0,k,l;
		
		memset(no,0,sizeof(no));
		for(int i = 0;i < n;i++)
		{
			scanf("%I64d%I64d",&k,&l);
			no[i].d = min(k*2,l);
			no[i].o = min(k,l);
			sum += no[i].o;
			
		//		printf("%I64d %I64d\n",min(no[i].k,no[i].l),sum);
		}
		sort(no,no+n);
		
		
		for(int i = n-1;i>n-1-f;i--)
		{
			
			sum += no[i].d;
			sum -= no[i].o;
		//	printf("%I64d %I64d %I64d\n",sum,no[i].d,no[i].k);
		}
		printf("%I64d\n",sum);
	}



 return 0;
}


