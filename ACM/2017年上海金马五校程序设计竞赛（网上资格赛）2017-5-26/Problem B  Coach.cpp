#include<bits/stdc++.h>

using namespace std;


int father[50002],a,b,m,n,p;
int find(int x)
{
	if(father[x]!=x)
	father[x]=find(father[x]);
	/*
	x���������е��ˣ�father[x]���������������һ�����������˶���һ���������ݹ�ϵ
	�൱�������е�һ���������е�Ԫ�ض����һ��Ԫ�������ݹ�ϵ
	����ʱֻҪ��Ԫ����ָ���father[x]=x��Ԫ��(����Ԫ��)
	Ȼ��Ƚ�����Ԫ�صĸ�Ԫ���Ƿ���ͬ�Ϳ����ж����ϵ
	*/
	return father[x];
}
int num[5555];

int main()
{
	int n,m;
	int a,b;
	while(~scanf("%d%d",&n,&m))
	{
		memset(num,0,sizeof(num));
		memset(father,0,sizeof(father));
		
		for(int i=1;i<=n;i++)
    		father[i]=i;
		for(int i=1;i<=m;i++)
	    {
	      scanf("%d%d",&a,&b);
	      a=find(a);
	      b=find(b);
	      father[a]=b;
	    }
		if(n%3)
		{
			printf("No\n");
			continue;
		}
		if((2*n/3)>m)
		{
			printf("No\n");
			continue;
		}
		for(int i = 1;i <= n;i++)
		{
			num[father[i]]++;
			printf("%d %d\n",i,father[i]);
		}
		int F = 0;
		for(int i = 1;i <= n;i++)
		{
			printf("%d %d\n",i,num[i]);
			if(num[i]%3)
			{
				F = 1;
				break;
			}
		}
		if(F)
		{
			printf("No\n");
		}
		else
		{
			printf("Yes\n");
		}
		
		
	}




 return 0;
}


