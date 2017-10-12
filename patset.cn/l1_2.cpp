#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>



using namespace std;
int main()

{
	int hh,mm;
	scanf("%d:%d",&hh,&mm);
	if(hh>12)
	{
		if(mm!=0)
		{
			hh++;
		}
		for(int i = 0;i<(hh-12);i++)
		{
			printf("Dang");
		}
		printf("\n");
	}
	else
	{
		if(hh<10&&mm<10)
		printf("Only 0%d:0%d.  Too early to Dang.\n",hh,mm);
		if(hh>=10&&mm<10)
		printf("Only %d:0%d.  Too early to Dang.\n",hh,mm);
		if(hh<10&&mm>=10)
		printf("Only %d:0%d.  Too early to Dang.\n",hh,mm);
		if(hh>=10&&mm>=10)
		printf("Only %d:%d.  Too early to Dang.\n",hh,mm);
	}
}
