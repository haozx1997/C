#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
using namespace std;

struct moonkcake
{
	long hav;
	double pric;
	double one;
}cake[10000];

int cmp( const void *a ,const void *b) 
{ 
return (*(moonkcake *)a).one < (*(moonkcake *)b).one ? 1 : -1; 
} 


int main()
{
	int N;
	while(~scanf("%d",&N))
	{
		
		int need;
		scanf("%d",&need);
		for(int i = 0;i < N;i++)
		{
			scanf("%d",&cake[i].hav);
		}
		for(int i = 0;i < N;i++)
		{
			scanf("%lf",&cake[i].pric);
		}
		for(int i = 0;i < N;i++)
		{
			cake[i].one = cake[i].pric /(double)cake[i].hav;
		}
		qsort(cake,N+1,sizeof(cake[0]),cmp);
//		for(int i = 0;i < N;i++)
//		{
//			printf("%d\n",cake[i].pric);
//		}
		long sum = 0;
		double ans = 0.0;
		int end = 0;
		for( int i = 0;i < N;i++)
		{
			sum += cake[i].hav;
			ans += cake[i].pric;
			if(sum > need)
			{
				end = i;
				break;
			}
		}
		sum -= cake[end].hav;
		ans -= cake[end].pric;
		long end_hav = need - sum;
		double end_pric = ((double)(end_hav)/cake[end].hav)*cake[end].pric;
		
		ans += end_pric;
		printf("%.2f\n",ans);
		memset(cake,0,sizeof(cake));
	
	}
	
	
	
	
	
	
	
	
	
	
	
	
}
