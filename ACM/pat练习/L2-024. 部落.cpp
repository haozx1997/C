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
	x代表例题中的人，father[x]中所存的数代表这一集合中所有人都与一个人有亲戚关系
	相当于例题中第一个集合所有的元素都与第一个元素有亲戚关系
	搜索时只要找元素所指向的father[x]=x的元素(即父元素)
	然后比较两个元素的父元素是否相同就可以判断其关系
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
