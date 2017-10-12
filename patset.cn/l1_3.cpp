#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<stdlib.h>

using namespace std;
int main()

{
	int al,bl,n;
	
	scanf("%d%d",&al,&bl);
	int anow = al,bnow = bl;
	scanf("%d",&n);
	while(n--)
	{
		int as,ap,bs,bp;
		scanf("%d%d%d%d",&as,&ap,&bs,&bp);
		if((as+bs)==ap&&(as+bs)!=bp)
		{
			anow--;
		}
		if((as+bs)==bp&&(as+bs)!=ap)
		{
			bnow--;
		}
		if(anow<0)
		{
			printf("A\n");
			printf("%d\n",bl-bnow);
			break;
		}
		if(bnow<0)
		{
			printf("B\n");
			printf("%d\n",al-anow);
			break;
		}
		
		
	}
	
	
	
}
