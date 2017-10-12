#include<stdio.h>

int p1,p2,p3,t1,t2;
int solve(int m)
{
	if(m<0)
	 return 0;
	
	if(m<=t1)
	{
		return m*p1;
	}
	if(m<=(t1+t2))
	{
		return t1*p1+(m-t1)*p2;
	}
	return t1*p1+t2*p2+(m-t1-t2)*p3;
}

int main()
{
//	freopen("1.in","r",stdin);
	int n;
	while(~scanf("%d",&n))
	{
		
		int l[200],r[200];
		int mel[200];
		scanf("%d%d%d%d%d",&p1,&p2,&p3,&t1,&t2);
		int ans = 0;
		int add;
		for(int i = 0;i < n;i++)
		{
			scanf("%d%d",&l[i],&r[i]);
			add = p1*(r[i]-l[i]);
			ans += add;
		}
		
		for(int i = 1;i < n;i++)
		{
			
			ans+=solve(l[i]-r[i-1]);
		}
		printf("%d\n",ans);
		
		
	}
}
