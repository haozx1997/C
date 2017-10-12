#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct st
{
	char col[20];
	int num;
}stu[200];

int cmp1(const void *a,const void *b)
{
      return (*(st*)b).num-(*(st*)a).num;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		for(int i = 0 ;i < n ;i++)
		{
			scanf("%s%d",&stu[i].col,&stu[i].num);
		}
		qsort(stu,n,sizeof(stu[0]),cmp1);
		for(int i = 0 ;i < n-1 ;i++)
		{
			printf("%s ",stu[i].col);
		}
		printf("%s",stu[n-1].col);
		
		printf("\n");
	}
	
	
}
