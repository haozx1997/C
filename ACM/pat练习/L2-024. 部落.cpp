#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<bits/stdc++.h>
using namespace std;
 
int father[50002],a,b,m,n,p;
int find(int x)
{
	if(father[x]!=x)
		father[x]=find(father[x]);
	return father[x];
	/*
	x���������е��ˣ�father[x]���������������һ�����������˶���һ���������ݹ�ϵ
	�൱�������е�һ���������е�Ԫ�ض����һ��Ԫ�������ݹ�ϵ
	����ʱֻҪ��Ԫ����ָ���father[x]=x��Ԫ��(����Ԫ��)
	Ȼ��Ƚ�����Ԫ�صĸ�Ԫ���Ƿ���ͬ�Ϳ����ж����ϵ
	*/
	
}

int Union(int a,int b)
{
	a=find(a);
    b=find(b);
      father[a]=b;
 } 

int pp[10010][10100];
int main()
{
  int n;
  while(~scanf("%d",&n))
  {
  		int maxx = 0;
  		
  		for(int i = 0;i < n;i++)
  		{
  			
  			scanf("%d",&pp[i][0]);
  			for(int ii = 1;ii <= pp[i][0];ii++)
  			{
  				scanf("%d",&pp[i][ii]);
  				maxx = max(maxx,pp[i][ii]);
			  }
			  
		  }
		for(int i = 0 ;i<=maxx;i++)
		{
			father[i] = i;
		  }  
		for(int i = 0;i<n;i++)
		{
			for(int ii = 1;ii<pp[i][0];ii++)
			{
				Union(pp[i][ii],pp[i][ii+1]);
			}
		  }  
		
		
		set<int>S;
		S.clear();
		for(int i = 1 ;i<=maxx;i++)
		{
			
			S.insert(find(i));
		}  
		printf("%d %d\n",maxx,S.size());
		int qn;
		scanf("%d",&qn);
		for(int i =0;i<qn;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a = find(a);
			b = find(b);
			if(a== b)
			{
				printf("Y\n");
			}
			else
			{
				printf("N\n");
			}
		  }  
  }
  return 0;
} 
