#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int a,b;

struct lalala
{
	int g;
	char name[8],n[6];
 } ;struct lalala la[100010];

int  cmp1(static void*a,static void*b)
{
	struct lalala*x=(lalala*)a;
	struct lalala*y=(lalala*)b;
	return strcmp((*x).n,(*y).n);
}

int  cmp2(static void*a,static void*b)
{
	struct lalala*x=(lalala*)a;
	struct lalala*y=(lalala*)b;
	if(strcmp((*x).name,(*y).name)==0)
	    return strcmp((*x).n,(*y).n);
	return strcmp((*x).name,(*y).name);
}

int  cmp3(static void*a,static void*b)
{
	struct lalala*x=(lalala*)a;
	struct lalala*y=(lalala*)b;
	if((*x).g==(*y).g)
	    return strcmp((*x).n,(*y).n);
	return (*x).g-(*y).g;
}

int main()
{
	int i,j=1;
	while(scanf("%d%d",&a,&b),a!=0 || b!=0)
	{
		
		for(i=0;i<a;i++)
		  scanf("%s%s%d",la[i].n,la[i].name,&la[i].g);
		switch(b)
		{
			case 1: qsort(la,a,sizeof(lalala),cmp1);break;
			case 2: qsort(la,a,sizeof(lalala),cmp2);break;
			case 3: qsort(la,a,sizeof(lalala),cmp3);break;
		}
		printf("Case %d:\n",j);j++;
		for(i=0;i<a;i++)
		  printf("%s %s %d\n",la[i].n,la[i].name,la[i].g);
	}
	return 0;
	
}
