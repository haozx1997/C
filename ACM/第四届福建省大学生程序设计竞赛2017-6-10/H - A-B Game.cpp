#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{	
//	printf("%d\n",99%((99/2)+1));
	int T;
	scanf("%d",&T);
	
	for(int II = 0;II < T;II++)
	{
		long long n,m,nn;
		scanf("%I64d%I64d",&n,&m);
		nn = n;
		int o = 0;
		
		while(1)
		{
			if(n<=m)
			{
				break;
			}
			
			if(n!=2)
			{
				long long n2 = (n/2)+(long long)1;
				n = n-(n%n2);
			}
			else
			{
				n = 1;
			}
	//		printf("%d\n",n);
			o++;
		}
		
	
		printf("Case %d: %d\n",II+1,o);
		
	}





 return 0;
}



