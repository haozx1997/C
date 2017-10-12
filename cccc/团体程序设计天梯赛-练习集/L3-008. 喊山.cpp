#include<stdio.h>
#include<string.h>
#include<stack>
#include<stdlib.h>


struct MT
{
	int n;
	int nbn;
	int nber[3];
}mt[10010];


int main()
{
	memset(mt,0,sizeof(mt));
	int N,l,qn;
	scanf("%d%d%d",&N,&l,&qn);
	for(int i = 0;i < l;i++)
	{
		int mt_e,mt_en;
		scanf("%d%d",&mt_e,&mt_en);
		mt[mt_e].nber[mt[mt_e].nbn++] = mt_en;
		mt[mt_en].nber[mt[mt_en].nbn++] = mt_e;
		
	}
	for(int i = 0;i<=N;i++)
	{
		printf("ɽ %d :",i);
		for(int j = 0;j<mt[i].nbn;j++)
		{
			printf("%d ",mt[i].nber[j]);
		}
		printf("\n");
	}
	while(qn--)
	{
		int q;
		scanf("%d",&q);
		if(mt[q].nbn == 0)
		{
			printf("0\n");
		}
		else printf("UNKNOW\n");
	}
	
	
	
}
