#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

struct st
{
	char num[20];
	char name[20];
	int grade;
}stu[100100];

int cmp1(const void *a,const void *b)
{
      return strcmp((*(st*)a).num,(*(st*)b).num);
}


int cmp2(const void *a,const void *b)
{
	struct st*aa=(st*)a;
	struct st*bb=(st*)b;
	if(strcmp((*(st*)a).name,(*(st*)b).name))
	   return strcmp((*(st*)a).name,(*(st*)b).name);
	else 
	   return strcmp((*(st*)a).num,(*(st*)b).num);
}



int cmp3(const void *a,const void *b)
{
	struct st*aa=(st*)a;
	struct st*bb=(st*)b;
	if(aa->grade!=bb->grade)
	   return (((aa->grade)>(bb->grade))?1:-1);
	else 
	   return strcmp((*(st*)a).num,(*(st*)b).num);
}
int main()
{
	int n,c;
	int t=1;
	while(scanf("%d%d",&n,&c),n)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%s%s%d",&stu[i].num,stu[i].name,&stu[i].grade);
		}
		switch(c)
		{
			case 1:qsort(stu,n,sizeof(stu[0]),cmp1) ;break;
			case 2:qsort(stu,n,sizeof(stu[0]),cmp2) ;break;
			case 3:qsort(stu,n,sizeof(stu[0]),cmp3) ;break;
		}
		
		printf("Case %d:\n",t++);
		for(int i=0;i<n;i++)
		{
			printf("%s %s %d\n",stu[i].num,stu[i].name,stu[i].grade);
		}		
	}
	
 } 
